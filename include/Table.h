#ifndef TABLE_H
#define TABLE_H
#include <string>

using namespace std;

struct Table {
  int id, virt_add, physical, read; //Clock is for when it was accessed. 
  bool dirty; 

  Table(int id, int virt_add, int physical, bool dirty, int read): id (id), virt_add (virt_add), physical (physical), dirty (false), read (read) {};
  
};

#endif
