#ifndef OS_H
#define OS_H

#include <vector>
#include <map>
#include "process.h"
#include "page.h"



class OS{
public:
	enum SwapPolicy { fifo, lru, ran };

	OS(SwapPolicy policy, int memSize);
	//void setPolicy(swapPolicy);
	void createProcess(int id);
	void allocate(int id, int virAdd);
	void read(int time, int id, int virAdd);
	void write(int time, int id, int virAdd);
	void free(int time, int id, int virAdd);
	void kill(int id); //free all memory of procress
	void print();

private:
	Page* getPage(int id, int virAdd);
	std::map<int, Process*> processList; //with procress id being the key
	SwapPolicy policy;
	int memSize;
	Page** pMem; //array of pages as physical Memory

	std::vector<Page> swapMem;	//swap memory

};

#endif