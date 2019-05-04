#ifndef MEMORY_H
#define MEMORY_H
#include <string>

using namespace std;

struct Memory {
  int id, virt_add;
  string action;
  bool started; 
  Memory(int id, string action, int virt_add): id(id), action (action),  virt_add (virt_add), started(false) {};
  
};

#endif
