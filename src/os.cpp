#include "os.hpp"
#include <sstream>
#include <random>
#include <iostream>


OS::OS(SwapPolicy policy, int memSize){
	pMem = new Page*[memSize];
	this->policy = policy;
	this->memSize = memSize;
	phyCount = 0;
	fifoCount = 0;
}

void OS::createProcess(int id){
	Process* newP = new Process(id);
	processList[id] = newP;
}

Page* OS::getPage(int &id, int &virAdd){
	//Find procress by id
	Process* currPro = processList[id];
	if (currPro == NULL)
		return NULL;

	//get page by virAdd
	return currPro->getPage(virAdd);
}

void OS::read(int time, int id, int virAdd){
	rw(time, id, virAdd, r);
}


void OS::write(int time, int id, int virAdd){
	rw(time, id, virAdd, w);
}

void OS::rw(int &time, int &id, int &virAdd, RW opp){
	Page* currPage = getPage(id, virAdd);
	
	if (currPage == NULL){ //kill process if page is not found
		kill(id);
		return;
	}

	//swap back to memory if page is in swap memory
	if(currPage->isSwapped())
		fromSwapToPhy(currPage);

	if(opp == r)
		currPage->read(time);
	else
		currPage->write(time);
}

void OS::allocate(int id, int virAdd){
	
	//find process using map
	Process* currPro = processList[id];
	if(currPro == NULL || currPro->isKilled())
		return; 

	Page* newP = new Page(id, virAdd);

	if(phyCount == memSize) //if swap is required
		swap(newP);
	else{
		int index = findFreeInPhy();
		pMem[index] = newP;
		newP->toPhysical(index);
		phyCount++;
	}
	//increment count to record size of physical memory
	
	//add page
	currPro->addPage(newP);
	

}

int OS::findFreeInPhy(){
	for(int i = 0; i < memSize; i++){
		if(pMem[i] == NULL)
			return i;
	}
}


void OS::free(int time, int id, int virAdd){
	//Page* currPage = getPage(id, virAdd);
	
	Process* currPro = processList[id];// get procress
	Page* temp = currPro->free(virAdd); //remove page from pageTable
	if (temp == NULL){ //kill procress if page doesnt exist
		kill(id);
		return;
	}

	if(temp->isSwapped())
		for(int i = 0; i < swapMem.size(); i++){
			if(swapMem[i] == temp){
				swapMem.erase(swapMem.begin()+i);
				return;
			}
		}

	int pIndex = temp->getPhyAdd();
	delete temp;
	pMem[pIndex] = NULL;
	phyCount--;
}

void OS::kill(int id){
	Process* curr = processList[id];
	if(curr == NULL)
		return;

	while(!curr->empty()){
		free(0, id, curr->getOneVirAdd());
	}
	curr->kill();
}

std::string OS::print(){
	std::stringstream ss;
	for (std::map<int,Process*>::iterator it=processList.begin(); it!=processList.end(); ++it){
		Process *start = it->second;
		if(start != NULL)
			ss << start->getPageTable() << "\n";
	}
	
	ss << "\nSWAP\n";
	for (int i = 0; i < swapMem.size(); i++){
		ss << "PROCESS\t" << swapMem[i]->getProcessId();
		ss << "\tVIRTUAL\t\t" << swapMem[i]->getVirAdd() << "\n";
	}

	ss << "\nPHYSICAL\n";
	for (int i = 0; i < memSize; i++){
		Page* curr = pMem[i];
		ss << i << "\t";
		if(curr == NULL)
			ss << "FREE \n";
		else{
			ss << "PROCESS\t" << curr->getProcessId() << "\tVIRTUAL\t" << curr->getVirAdd();
			ss <<  (curr->isDirty()? "\tDirty": "") << "\n";
		}
	}

	return ss.str();

}

void OS::fromSwapToPhy(Page* target){
	//find and remove target from swap memory
	for(int i = 0; i < swapMem.size(); i++){
		if (swapMem[i] == target){
			swapMem.erase(swapMem.begin()+i);
			break;
		}
	}
	//put target to physical memory
  	swap(target);
}

//TODO: OS::swap
void OS::swap(Page* target){
	int indexToSwap;
	bool foundNotDirty = false;

	//find dirty page
	for(int i = 0; i < memSize && !foundNotDirty ; i++){
		if(!pMem[i]->isDirty()){
			indexToSwap = i;
			foundNotDirty = true;
		}
	}

	if(!foundNotDirty){ // do policy if no dirty page found
		switch(policy){
			case fifo: indexToSwap = getIndexFifo(); break;
			case lru: indexToSwap = getIndexLru(); break;
			case ran: indexToSwap = getIndexRan(); break;	
		}
	}

	Page* swapOut = pMem[indexToSwap]; //get page to swap out
	swapOut->toSwap();
	swapMem.push_back(swapOut); //push to swap memory
	
	target->toPhysical(indexToSwap);
	pMem[indexToSwap] = target; //put in physical memory
}

int OS::getIndexFifo(){
	int index = fifoCount % memSize;
	fifoCount++;
	
	return index;	
}

int OS::getIndexLru(){
	int min = pMem[0]->getLastRW();
	int indexLRU = 0;

	for (int i = 1; i < memSize; i++) {
		if (pMem[i]->getLastRW() < min) {
			indexLRU = i;
		}
	}

	return indexLRU;	
}

int OS::getIndexRan(){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, memSize-1);
	int a = dis(gen);
	return a;	
}