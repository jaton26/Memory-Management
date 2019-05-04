#include "os.h"

//Does each process have their own id? Or is it 100, 200, etc?
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
