#include "page.hpp"


Page::Page(int processId, int virAdd){
	this->processId = processId;
	this->virAdd = virAdd;
}

void Page::read(int time){
	lastRW = time;
};

void Page::write(int time){
	lastRW = time;
	dirty = true;
};

bool Page::isDirty(){
	return dirty;
}

void Page::toSwap(){
	swapped = true;
}


void Page::toMem(){
	swapped = false;
}

bool Page::isSwapped(){
	return swapped;
}