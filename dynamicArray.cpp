#include <iostream>
using namespace std;
int main(){
  int size;
  int *array;
  int *newArray;
  cout << "Size of array: ";
  cin >> size;
  array  = new int[size];
  for (int i = 0; i < size; i++) {
    cout << i << ": ";
    cin >> array[i];
  }

  cout << "\nSize of array again: ";
  cin >> size;
  newArray  = new int[size];
  for (int i = 0; i < size; i++) {
    newArray[i] = array[i];
    cout << i << ": " << array[i] << endl;;
  }
  cout << "\n";
  delete [] array;
}
