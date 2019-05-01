#include <iostream>
#include "Memory.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue> 

using namespace std;

int main(){
  int size;
  int i = 0;
  ifstream in("memory.dat");
  std::string line;
  std::string temp;
  std::vector<Memory> list;
  int page = 0;

  while(std::getline(in, line))
  {
      std::istringstream iss(line);

      std::getline(iss,temp,' ');
      int id = std::stoi(temp);
      std::getline(iss,temp,' ');
      std::string action = temp;
      if (std::getline(iss,temp,' ')) {
	page = std::stoi(temp);
      } else {
        page = 0;
      }
      cout << id << " ";
      cout << action << " ";
      if (page != 0)
        cout << page;
      cout << endl;
      
      
      //Memory newJob(id, action, page);
      //list.push_back(newJob);
      i++;
  }
  return 0;
}
