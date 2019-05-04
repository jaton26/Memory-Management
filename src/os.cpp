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
		swap(currPage);

	if(opp == r)
		currPage->read(time);
	else
		currPage->write(time);
}

void OS::allocate(int id, int virAdd){
	
	//TODO: find process using map
	Process* currPro = processList[id];
	currPro->id = id;

	Page* newP = new Page(virAdd);

	if(phyCount == memSize)
		swap(newP);
	//increment count to record size of physical memory
	phyCount++;
	//add page
	addPage(newP);
	

}

void OS::free(int time, int id, int virAdd){
	//swap???
	Process* currPro = processList[id];
	Page* temp = currPro->free(virAdd);
	//if(temp->isSwapped())
		//find page in swap mem
		//remove page from swap mem

	//phyCount--
	delete temp;
}

void OS::kill(int id){

}

void OS::print(){
	
}

//TODO: OS::swap
void OS::swap(Page* target){
	int indexToSwap;
	switch(policy){
		case fifo: indexToSwap = getIndexFifo(); break;
		case lru: indexToSwap = getIndexLru(); break;
		case ran: indexToSwap = getIndexRan(); break;	
	}
	Page* swapOut = pMem[indexToSwap];
	swapMem.push_back(swapOut);
	pMem[indexToSwap] = target;
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