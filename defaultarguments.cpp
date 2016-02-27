#include <iostream>
#include <string>

using namespace std;

void showText(string str = "unknown", int nrOfTimes = 2);

int main(){

  showText();
  showText(4);
  return 0;
 }

void showText(string str, int nrOfTimes){
  cout << str << " " << nrOfTimes << endl;
}
