#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename T>
int linear_search(T arr[], int size, T key){
		int pos = -1;
		for(int i = 0; i < size; i++){
				if(arr[i] == key){
						pos = i;
				}
		}
		return pos;
}

template <typename T>
int binary_search(T arr[], int size, T key){
		int endIndex = sizeof(arr/sizeof(T))-1;
		int startIndex = 0;
		int midIndex = (startIndex+endIndex)/2;

		while(arr[midIndex] != key){
				if(arr[midIndex] < key){
				    startIndex = midIndex + 1;
				}
				else{
					endIndex = midIndex -1;
				}
				midIndex = (startIndex + endIndex) /2;
		}

		return midIndex;

}
int main(void){
	const int size = 6;	
	int arr[size] = {2,5,3,7,9,1};
	cout << binary_search(arr,size,3) << endl;
	return 0;
}
