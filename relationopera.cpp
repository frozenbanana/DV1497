#include <iostream>
#include <string>

using namespace std;

int main(){

  string foo = "alpha";
  string bar = "beta";

  if(foo == bar)
    std::cout << "foo and abr are equal" << std::endl;
  if (foo != bar) {
    std::cout << "foo and bar are not equal" << std::endl;
  }
  if (foo < bar) {
    std::cout << "foo is less than bar" << std::endl;
  }
   if (foo > bar) {
    std::cout << "foo is more than bar" << std::endl;
  }

  return 0;
 }
