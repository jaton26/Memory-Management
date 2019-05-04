#ifndef MEMORY_H
#define MEMORY_H
#include <string>

using namespace std;

struct Memory {
<<<<<<< HEAD:include/memory.h
  int id, virt_add;
  string action;
  bool started; 
  Memory(int id, string action, int virt_add): id(id), action (action),  virt_add (virt_add), started(false) {};
=======
  int id, virt_add, time, phys_add;
  int read, write;
  bool dirty;
  string action;
  bool started; 
  Memory(int id, string action, int virt_add, int time): id(id), action (action), virt_add (virt_add), started(false), time (time) {};
>>>>>>> 7e12a2285dddb50f5aad5f6688b6597f06e96cf9:include/Memory.h
  
};

#endif
