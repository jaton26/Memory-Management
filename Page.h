#ifndef PAGE_H
#define PAGE_H
#include <string>

using namespace std;

struct Page {
  int id, virt_add, physical, clock; //Clock is for when it was accessed. 
  bool dirty, read; 
  Page(int id, int virt_add, int physical, int clock): id(id), virt_add (virt_add), physical (physical), clock (clock), dirty(false), read(false) {};
  
};

#endif
