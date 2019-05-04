#include <iostream>
<<<<<<< HEAD:hw3.cpp
#include "Memory.h"
#include "Page.h"
=======
>>>>>>> master:src/hw3.cpp
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
<<<<<<< HEAD:hw3.cpp
#include <queue> 
#define MAX 19
=======
#include <queue>
#include "memory.h"
#include "os.h"
>>>>>>> master:src/hw3.cpp

using namespace std;

void making_page_list(vector<Memory> ready, int size){
  vector<Page> final_list;
  //cout << list->id;
  vector<Page> table; //This will hold the 20 physical page table data. 
  int count = 1; //Will keep track of which page will be ued next. 
  for(int i = 0; i < size; i++){
    Memory *line = &ready[i];
    Page *final_line;
    if(line->action == "A"){
      final_line->id = line->id;
      final_line->virt_add = line->virt_add;
      final_line->physical = count;
      count++;
    }
    else if(line->action == "W"){
      
    }
  }
}

int main(){
  int size;
  int i = 0;
  ifstream in("memory.dat");
  std::string line;
  std::string temp;
  std::vector<Memory> list;
  int dummy = 0;
  
  int memSize = 20;
  OS*policies[3];
  policies[0] = new OS(OS::SwapPolicy::fifo, memSize);
  policies[0] = new OS(OS::SwapPolicy::lru, memSize);
  policies[0] = new OS(OS::SwapPolicy::fifo, memSize);

  while(std::getline(in, line))
  {
      int virt_add;
      std::istringstream iss(line);

      std::getline(iss,temp,' ');
      int id = std::stoi(temp);
      std::getline(iss,temp,' ');
      std::string action = temp;
      if (std::getline(iss,temp,' ')) {
	virt_add = std::stoi(temp);
      } 
      else {
	virt_add = dummy;
      }
      cout << id << " ";
      cout << action << " ";
      if (virt_add)
        cout << virt_add;
      cout << endl;
      
      
      Memory newJob(id, action, virt_add);
      list.push_back(newJob);
      i++;
      //cout << "ID: " << newJob.id << endl;
      //cout << "Action: " << newJob.action << endl;
      //cout << "Virtual Address: " << newJob.virt_add << endl << endl;
  }
<<<<<<< HEAD:hw3.cpp
  making_page_list(list, i);
=======

>>>>>>> master:src/hw3.cpp
  return 0;
}
