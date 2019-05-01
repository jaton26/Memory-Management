#ifndef PAGE_H
#define PAGE_H

class Page{
public:
	Page(int processId, int virAdd);
	void read(int time);
	void write(int time);
	bool isDirty();
	bool isSwapped();

private:
	int processId;
	int virAdd; //virtual address
	int lastRW;
	bool dirty;
	bool swapped;
};

#endif