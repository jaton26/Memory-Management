#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include "memory.h"
#include "os.h"

using namespace std;

int main(){
  int size;
  int i = 0;
  ifstream in("memory.dat");
  std::string line;
  std::string temp;
  std::vector<Memory> list;
  int dummy;
  
  int memSize = 20;
  OS*policies[3];
  policies[0] = new OS(OS::SwapPolicy::fifo, memSize);
  policies[0] = new OS(OS::SwapPolicy::lru, memSize);
  policies[0] = new OS(OS::SwapPolicy::fifo, memSize);

  while(std::getline(in, line))
  {
      int page;
      std::istringstream iss(line);

      std::getline(iss,temp,' ');
      int id = std::stoi(temp);
      std::getline(iss,temp,' ');
      std::string action = temp;
      if (std::getline(iss,temp,' ')) {
	page = std::stoi(temp);
      } else {
	page = dummy;
      }
      cout << id << " ";
      cout << action << " ";
      if (page)
        cout << page;
      cout << endl;
      
      
      //Memory newJob(id, action, page);
      //list.push_back(newJob);
      i++;
  }

  return 0;
}
