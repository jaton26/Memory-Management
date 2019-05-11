#ifndef PROCRESS_H
#define PROCRESS_H

#include <vector>
#include <map>
#include "page.hpp"

class Process{
public:
	Process(int id): id(id), killed(false){};
	int getId();
	void addPage(Page*);
	Page* free(int virAdd);
	Page* getPage(int virAdd);
	void getPageCount();
	std::string getPageTable();
	bool empty(){return pageTable.size() == 0; };
	int getOneVirAdd();
	void kill();
	bool isKilled();
private:
	int id;
	bool killed;
	std::map<int, Page*> pageTable; //with virtual address being key
};

#endif