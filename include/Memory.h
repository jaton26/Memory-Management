#ifndef MEMORY_H
#define MEMORY_H
#include <string>

using namespace std;

struct Memory {
  int id, virt_add, time, phys_add;
  int read, write;
  bool dirty;
  string action;
  bool started; 
  Memory(int id, string action, int virt_add, int time): id(id), action (action), virt_add (virt_add), started(false), time (time) {};
  
};

//static auto arrivalCmp = [](Job&lhs, Job&rhs){return lhs.arrival<rhs.arrival;};
//static auto remainCmp = [](Job&lhs, Job&rhs){return lhs.remain>rhs.remain;};

#endif
