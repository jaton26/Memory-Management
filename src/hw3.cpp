#include <iostream>
<<<<<<< HEAD
<<<<<<< HEAD:hw3.cpp
#include "Memory.h"
#include "Page.h"
=======
>>>>>>> master:src/hw3.cpp
=======
#include "Memory.h"
#include "page.h"
#include "Table.h"
#include "os.h"
>>>>>>> 7e12a2285dddb50f5aad5f6688b6597f06e96cf9
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
<<<<<<< HEAD
<<<<<<< HEAD:hw3.cpp
#include <queue> 
#define MAX 19
=======
#include <queue>
#include "memory.h"
#include "os.h"
>>>>>>> master:src/hw3.cpp
=======
#include <queue> 
#define MAX 19
>>>>>>> 7e12a2285dddb50f5aad5f6688b6597f06e96cf9

using namespace std;
/*
void fifoSwap(std::vector<Memory> ready_list, int time){
  std::vector<Memory> final_list;
  int i = 0; //Keeps track of iterating vector. 
  int count = 1; //Keeps track of final_list. Can only go up to 19. 

  while(!ready_list.empty()){
    Memory *line = &ready_list[i];
    if(line->action == "C"){
      line->started = true;
      final_list.push_back(*line);

      Memory *line = &final_list[i];
      cout << "CREATE: " << line->started << endl;

      ready_list.erase(ready_list.begin());
    }

    else if(line->action == "A"){
      line->phys_add = count;
      //i++;
      count++;
      final_list.push_back(*line);
      ready_list.erase(ready_list.begin());

      Memory *line = &final_list[i];
      cout << "PHYSICAL: " << line->phys_add << endl;
      cout << ready_list.size() << endl << endl;
    }

    else if(line->action == "R"){
      int loopIterator = 0; //Loops to find the VA that wants to read from. 
      Memory *temp = &final_list[loopIterator];
      int size = final_list.size();
      while(loopIterator != size){
        cout << "WHY????" << endl;
        if(temp->virt_add == line->virt_add){
          line->read = line->time;
          final_list.push_back(*line);
          ready_list.erase(ready_list.begin());
          Memory *line = &final_list[loopIterator];
          cout << "READ: " << line->read << endl;
        }
        loopIterator++;
        Memory *temp = &final_list[loopIterator];
      }
    }

  }

<<<<<<< HEAD
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

=======
}
*/
>>>>>>> 7e12a2285dddb50f5aad5f6688b6597f06e96cf9
int main(){
  int size;
  int time = 1;
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
<<<<<<< HEAD
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
=======
  
      
      //cout << "ID: " << newJob.id << endl;
      //cout << "Action: " << newJob.action << endl;
      //cout << "Virtual Address: " << newJob.virt_add << endl;
      //cout << "Time: " << newJob.time << endl << endl; 
  }
  //making_page_list(list, i);
  //fifoSwap(list, time);
>>>>>>> 7e12a2285dddb50f5aad5f6688b6597f06e96cf9
  return 0;
}
