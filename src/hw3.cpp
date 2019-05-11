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

int main(){
  ifstream in("memory.dat");
  std::string line;
  std::string temp;
  int time = 0;
  //std::vector<Memory> list;
  
  int memSize = 20; //TODO: Change back to 20. 
  OS*policies[3];
  policies[0] = new OS(OS::fifo, memSize);
  policies[1] = new OS(OS::lru, memSize);
  policies[2] = new OS(OS::ran, memSize);

  while(std::getline(in, line)){
    int virAdd = 0;
    std::istringstream iss(line);
    std::getline(iss,temp,' ');
    int id = std::stoi(temp);
    std::getline(iss,temp,' ');
    std::string action = temp;
    if(std::getline(iss,temp,' ')){
      virAdd = std::stoi(temp);
    }

    for(int i = 0; i < 3; i++){
      switch(action[0]) {
        case 'C':
          policies[i]->createProcess(id);
          break;
        case 'T':
          policies[i]->kill(id);
          break;
        case 'A':
          policies[i]->allocate(id, virAdd);
          break;
        case 'R':
          policies[i]->read(time, id, virAdd);
          break;
        case 'W':
          policies[i]->write(time, id, virAdd);
          break;
        case 'F':
          policies[i]->free(time, id, virAdd);
          break;
        default:
          cout << "Error. ";
      }
    } 
    time++;
  }
  cout << "*************** Fifo **************\n";
  cout << policies[0]->print() << endl;
  cout << "*************** LRU ***************\n";
  cout << policies[1]->print() << endl;
  cout << "************* Random *************\n";
  cout << policies[2]->print() << endl;

  return 0;
}
