#include <iostream>
#include "Memory.hpp"
#include "page.hpp"
#include "os.hpp"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue> 
#define MAX 19

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

}
*/
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
  policies[1] = new OS(OS::SwapPolicy::lru, memSize);
  policies[2] = new OS(OS::SwapPolicy::fifo, memSize);

  while(std::getline(in, line))
  {
    
      
      //cout << "ID: " << newJob.id << endl;
      //cout << "Action: " << newJob.action << endl;
      //cout << "Virtual Address: " << newJob.virt_add << endl;
      //cout << "Time: " << newJob.time << endl << endl; 
  }
  //making_page_list(list, i);
  //fifoSwap(list, time);
  return 0;
}
