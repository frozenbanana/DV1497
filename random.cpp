#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

  cout << "first number: " << rand() % 100 << endl;

  srand(time(NULL));

  cout << "random number: " << rand() % 100 << endl;

  srand(1);

  std::cout << "Again the first number: " << rand() % 100 << std::endl;
  return 0;
 }
