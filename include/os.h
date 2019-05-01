#ifndef OS_H
#define OS_H

#include <vector>
#include "procress.h"
#include "page.h"

enum swapPolicy { fifo, lru, random };

class OS{
public:
	OS(swapPolicy policy, int memSize);
	void createProcress(int id);
	void allocate(int id, int virAdd);
	void read(int id, int virAdd);
	void write(int id, int virAdd);
	void kill(int id);
	void print();

private:
	swapPolicy policy;
	int memSize;
	Page* pMem; //array of pages as physical Memory
	std::vector<Page> swapMem;	//swap memory
};

#endif