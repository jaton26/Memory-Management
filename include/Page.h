#ifndef TABLE_H
#define TABLE_H
#include <string>

using namespace std;

struct Table {
  int id, virt_add, physical, clock; //Clock is for when it was accessed. 
  bool dirty, read; 
  Page(int id, int virt_add, int physical, int clock, bool dirty, bool read): id(id), virt_add (virt_add), physical (physical), clock (clock), dirty(false), read(false) {};
  
};

#endif
