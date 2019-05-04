#ifndef PROCRESS_H
#define PROCRESS_H

#include <vector>
#include <map>
#include "page.h"

class Process{
public:
	Process(int id): id(id){};
	int getId();
	void addPage(Page);
	void removePage(Page* pageAdd);
	void printPageTable();

private:
	int id;
	std::map<int, Page> pageTable; //with virtual address being key
};

#endif