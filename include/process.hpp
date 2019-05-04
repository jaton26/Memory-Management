#ifndef PROCRESS_H
#define PROCRESS_H

#include <vector>
#include <map>
#include "page.hpp"

class Process{
public:
	Process(int id): id(id){};
	int getId();
	void addPage(Page*);
	Page* free(int virAdd);
	std::string printPageTable();

private:
	int id;
	std::map<int, Page*> pageTable; //with virtual address being key
};

#endif