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
	Page* getPage(int virAdd);
	void getPageCount();
	std::string getPageTable();
	bool empty(){return pageTable.size() == 0; };
	int getOneVirAdd();

private:
	int id;
	std::map<int, Page*> pageTable; //with virtual address being key
};

#endif