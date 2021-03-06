#include "page.hpp"


Page::Page(int processId, int virAdd){
	this->processId = processId;
	this->virAdd = virAdd;
	dirty = false;
	swapped = false;
}

int Page::getVirAdd(){
	return virAdd;
}

int Page::getPhyAdd(){
	return phyAdd;
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

int Page::getProcessId(){
	return processId;
}

void Page::toPhysical(int physical){
	swapped = false;
	phyAdd = physical;
}

bool Page::isSwapped(){
	return swapped;
}

int Page::getLastRW() {
	return lastRW;
}