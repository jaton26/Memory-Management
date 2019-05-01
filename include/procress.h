#ifndef PROCRESS_H
#define PROCRESS_H

#include <vector>
#include "page.h"

class Procress{
public:
	Procress(int id): id(id){};
	int getId();
	void addPage(Page);
	void printPageTable();

private:
	int id;
	std::vector<Page> pageTable;
};

#endif