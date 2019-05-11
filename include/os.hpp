#ifndef OS_H
#define OS_H

#include <vector>
#include <map>
#include "process.hpp"
#include "page.hpp"



class OS{
public:
	enum SwapPolicy { fifo, lru, ran };
	enum RW{ r, w };
	OS(SwapPolicy policy, int memSize);
	//void setPolicy(swapPolicy);
	void createProcess(int id);
	void allocate(int id, int virAdd);
	void read(int time, int id, int virAdd);
	void write(int time, int id, int virAdd);
	void free(int time, int id, int virAdd);
	void kill(int id); //free all memory of procress
	std::string print();

private:
	std::map<int, Process*> processList; //with procress id being the key
	SwapPolicy policy;
	int memSize;
	int phyCount;
	int fifoCount;
	Page** pMem; //array of pages as physical Memory
	std::vector<Page*> swapMem;	//swap memory

	void swap(Page*);
	void rw(int &time, int &id, int &virAdd, RW opp);
	Page* getPage(int &id, int &virAdd);
	int getIndexFifo();
	int getIndexLru();
	int getIndexRan();
	void fromSwapToPhy(Page* target);
	int findFreeInPhy();

};

#endif