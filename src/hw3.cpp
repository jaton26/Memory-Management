#include <iostream>
//#include "Memory.hpp"
#include "page.hpp"
#include "os.hpp"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue> 

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
  ifstream in("memory.dat");
  std::string line;
  std::string temp;
  //std::vector<Memory> list;
  
  int memSize = 20;
  OS*policies[3];
  policies[0] = new OS(OS::fifo, memSize);
  policies[1] = new OS(OS::lru, memSize);
  policies[2] = new OS(OS::ran, memSize);

  while(std::getline(in, line)){
    std::istringstream iss(line);
    std::getline(iss,temp,' ');
    int id = std::stoi(temp);
    std::getline(iss,temp,' ');
    std::string action = temp;
    if(std::getline(iss,temp,' ')){
      int virAdd = std::stoi(temp);
      cout << virAdd << " ";
    }
    cout << id << " ";
    cout << action << endl;

    for(int i = 0; i < 3; i++){
      switch(action[0]) {
        case 'C':
          cout << "Process has been created. " << endl;
          //policies[i].createProcess(id);
          break;
        case 'T':
          break;
        case 'A':
          break;
        case 'R':
          break;
        case 'W':
          break;
        case 'F':
          break;
        default:
          cout << "Error. ";
      }
    }
      
      //cout << "ID: " << newJob.id << endl;
      //cout << "Action: " << newJob.action << endl;
      //cout << "Virtual Address: " << newJob.virt_add << endl;
      //cout << "Time: " << newJob.time << endl << endl; 
  }
  //making_page_list(list, i);
  //fifoSwap(list, time);
  return 0;
}
