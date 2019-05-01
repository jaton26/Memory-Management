#ifndef MEMORY_H
#define MEMORY_H
#include <string>

using namespace std;

struct Memory {
  int id, page;
  string action;
  bool started; 
  Memory(int id, string action, int page): id(id), action (action),  page (page), started(false) {};
  
};

//static auto arrivalCmp = [](Job&lhs, Job&rhs){return lhs.arrival<rhs.arrival;};
//static auto remainCmp = [](Job&lhs, Job&rhs){return lhs.remain>rhs.remain;};

#endif
