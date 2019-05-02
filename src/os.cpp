#include "os.h"

Page* OS::getPage(int id, int virAdd){
	//TODO: Find procress by id
	//TODO: get page by virAdd
	return NULL;
}

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