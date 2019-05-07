#ifndef PAGE_H
#define PAGE_H

class Page{
public:
	Page(int processId, int virAdd);
	int getVirAdd();
	int getPhyAdd();
	void read(int time);
	void write(int time);
	bool isDirty();
	int getProcessId();
	void toSwap();
	void toPhysical(int physical);
	bool isSwapped();

private:
	int processId;
	int virAdd; //virtual address
	int lastRW;
	bool dirty;
	bool swapped;
	int phyAdd; //physical address
};

#endif