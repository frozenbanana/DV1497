#include <iostream>
using namespace std;
int main(){
  int removeIndex;
  int arr[]= {1,2,3,4,5,6,7,8,9};
for (int i = 0; i < 9; i++) {
  cout << i << ":" << arr[i] << endl;
}
cout << "\nwhat index do you want to delete? ";
cin >> removeIndex;
int i = removeIndex;
while(i<8){
   arr[i] = arr[i+1];
   i++;
}
for (int i = 0; i < 8; i++) {
  cout << i << ":" << arr[i] << endl;
}

 return 0;
}
