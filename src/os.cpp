#include "os.h"

OS::OS(SwapPolicy policy, int memSize){
	pMem = new Page*[memSize];
	this->policy = policy;
	this->memSize = memSize;
}

void OS::createProcess(int id){
	Process* newP = new Process(id);
	processList[id] = newP;
}

Page* OS::getPage(int id, int virAdd){
	//TODO: Find procress by id
	//TODO: get page by virAdd
	return NULL;
}

//What do you mean swap back to memory?
void OS::read(int time, int id, int virAdd){

	Page* currPage = getPage(id, virAdd);
	//if currPage == NULL
		//kill procress because of page fault
	//else
	//TODO: Check if in swap, if it is, swap back to memory
	currPage->read(time);
}


void OS::write(int time, int id, int virAdd){

	Page* currPage = getPage(id, virAdd);
	//if currPage == NULL
		//kill procress because of page fault
	//else
	//TODO: Check if in swap, if it is, swap back to memory
	currPage->write(time);
}

void OS::allocate(int id, int virAdd){
	//Page* currPage = 

}

void OS::free(int time, int id, int virAdd){

}

void OS::kill(int id){

}

void OS::print(){
	
}
