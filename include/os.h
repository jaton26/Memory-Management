#ifndef OS_H
#define OS_H

#include <vector>
#include <map>
#include "procress.h"
#include "page.h"

enum swapPolicy { fifo, lru, ran };

class OS{
public:
	OS(swapPolicy policy, int memSize);
	void createProcress(int id);
	void allocate(int id, int virAdd);
	void read(int time, int id, int virAdd);
	void write(int time, int id, int virAdd);
	void free(int time, int id, int virAdd);
	void kill(int id); //free all memory of procress
	void print();

private:
	Page* getPage(int id, int virAdd);
	std::map<int, Procress> procressList; //with procress id being the key
	swapPolicy policy;
	int memSize;
	Page* pMem; //array of pages as physical Memory

	std::vector<Page> swapMem;	//swap memory

};

#endif