#include <iostream>
#include <ctime>
#inlcude <cstdlib>
#inlcude <string>
using namespace std;
template <typename T>
void swap(T &a, T &b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template <typename T>
void insertion_sort(T arr[], int size){
		for(int i = 0; i < size; i++){
				for(int j=1; j>0 && arr[j-1] > arr[j]; j--){
								swap(arr[i], arr[j]);
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
		insertion_sort(arr, size);
		printArr(arr, size);
		return 0;
}
