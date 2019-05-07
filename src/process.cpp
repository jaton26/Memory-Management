#include "process.hpp"
#include <sstream>
#include <vector>

int Process::getId(){
	return id;
}


void Process::addPage(Page* newP){
	int virAdd = newP->getVirAdd();
	pageTable[virAdd] = newP;
}


Page* Process::free(int virAdd){
	Page* temp = pageTable[virAdd];
	pageTable.erase(virAdd);
	return temp;
}


Page* Process::getPage(int virAdd){
	return pageTable[virAdd];
}

std::string Process::getPageTable(){
	std::stringstream ss;
	ss << "PROCESS " << id << "\n";
	for (std::map<int,Page*>::iterator it=pageTable.begin(); it!=pageTable.end(); ++it){
		ss << "Virtual\t" << it->first << "\t";
		Page* temp = it->second;
		if(temp->isSwapped()){
			ss << "SWAP\t";
		} else{
			ss << "PHYSICAL\t" << temp->getPhyAdd();
		}
		ss << "\n";
	}

	return ss.str();
}

int Process::getOneVirAdd(){
	return pageTable.begin()->first;
}

