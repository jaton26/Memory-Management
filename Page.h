#ifndef PAGE_H
#define PAGE_H
#include <string>

using namespace std;

struct Page {
  int id, virt_add, physical, clock; //Clock is for when it was accessed. 
  bool dirty, read; 
  Page(int id, int virt_add, int physical, int clock): id(id), virt_add (virt_add), physical (physical), clock (clock), dirty(false), read(false) {};
  
};

//static auto arrivalCmp = [](Job&lhs, Job&rhs){return lhs.arrival<rhs.arrival;};
//static auto remainCmp = [](Job&lhs, Job&rhs){return lhs.remain>rhs.remain;};

#endif