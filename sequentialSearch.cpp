#include <iostream>
using namespace std;
int main(){
  int arr[]= {20,40,100,80,10,60,50,90,30,40};
  std::cout << "Enter the number you want to find (from 10 to 100)" << std::endl;
  int key;
  std::cin >> key;
  int sorry = 0;
  int flag = 0;
  int i = 0;
for (i; i < 10; i++) {
  if (arr[i] == key) {
    flag = 1;
    sorry = 1;
  }
  if (flag) {
    std::cout << "Your number is at subscription position "<<i<< std::endl;
    flag = 0;
  }
}
if(sorry == 0)
   cout << "I am sorry \n";

 return 0;
}
