#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

template <typename T>
void swap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void babel_sort(T arr[], int size){
		for(int i = 0; i < size; i++){
				for(int j=1; j < size > arr[j]; j++){
					if(arr[i] > arr[j]){
						swap(arr[i], arr[j]);
					}	
				}
		}
}
template <typename T>
void printArr(T arr[], int size){
	for(int i = 0; i < size; i++){
		cout << arr[i] << " " << endl;
    }
}


int main(){
		const int size = 5;
		int arr[size];
		babel_sort(arr, size);
		printArr(arr, size);
		return 0;
}
