#include "os.hpp"

OS::OS(SwapPolicy policy, int memSize){
	pMem = new Page*[memSize];
	this->policy = policy;
	this->memSize = memSize;
	phyCount = 0;
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

	Page* newP = new Page(id, virAdd);

	if(phyCount == memSize) //if swap is required
		swap(newP);
	//increment count to record size of physical memory
	phyCount++;
	//add page
	currPro->addPage(newP);
	

}

void OS::free(int time, int id, int virAdd){
	Process* currPro = processList[id];// get procress
	Page* temp = currPro->free(virAdd); //remove page from pageTable
	if (temp == NULL){ //kill procress if page doesnt exist
		kill(id);
		return;
	}

	if(temp->isSwapped())
		fromSwapToPhy(temp);

	int pIndex = temp->getPhyAdd();
	delete temp;
	pMem[pIndex] = NULL;
}

void OS::kill(int id){

}

void OS::print(){
	
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
	for(int i = 0; i < memSize && !foundNotDirty; i++){
		if(pMem[i]->isDirty()){
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
	
	return 0;	
}

int OS::getIndexLru(){
	
	return 0;	
}

int OS::getIndexRan(){
	
	return 0;	
}