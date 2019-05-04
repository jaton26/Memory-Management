#include "os.hpp"

OS::OS(SwapPolicy policy, int memSize){
	pMem = new Page*[memSize];
	this->policy = policy;
	this->memSize = memSize;
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
	//Page* currPage = 

}

void OS::free(int time, int id, int virAdd){

}

void OS::kill(int id){

}

void OS::print(){
	
}

//TODO: OS::swap
void OS::swap(Page* target){
	
}