#ifndef MEMORY_H
#define MEMORY_H
#include <string>

using namespace std;

struct Memory {
  int id, virt_add;
  string action;
  bool started; 
  Memory(int id, string action, int virt_add): id(id), action (action), virt_add (virt_add), started(false) {};
  
};

//static auto arrivalCmp = [](Job&lhs, Job&rhs){return lhs.arrival<rhs.arrival;};
//static auto remainCmp = [](Job&lhs, Job&rhs){return lhs.remain>rhs.remain;};

#endif
