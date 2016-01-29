#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;

int main(){
  ofstream myfile ("example.txt");
  if (myfile.is_open()) {
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
    myfile.close();
  }
  else std::cout << "Unable to open file" << std::endl;
  
  ifstream myfileOut ("example.txt");
  string line;
  if (myfileOut.is_open()) {
    while(getline(myfileOut,line)){
      std::cout << line << std::endl;
    }
    myfileOut.close();
  }
  else std::cout << "Unable to open file" << std::endl;
  return 0;
 }
