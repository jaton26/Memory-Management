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

  while(std::getline(in, line))
  {
      std::istringstream iss(line);
      std::getline(iss,temp,' ');
      int id = std::stoi(temp);
      std::getline(iss,temp,' ');
      std::string action = temp;
      std::getline(iss,temp,' ');
      //int page = std::stoi(temp);
      cout << action << endl;
      cout << id << endl;
      
      //Memory newJob(id, action, page);
      //list.push_back(newJob);
      i++;
  }
  return 0;
}
