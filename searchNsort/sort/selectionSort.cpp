#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

/*
void generateRandomValues(int array[], int size){
	int rand;
	srand(time(NULL));
	for(int i = 0; i < size; i++){
	int rand  = rand() % 10 + 1;
	array[i] = rand;
	}

}
*/

template <typename T>
void printAllValues(T arr[], int size){
		for(int i = 0; i < size; i++){
				cout << arr[i] << " " << endl;
		}
}

template <typename T>
void selection_sort(T arr[], int size){
		T temp;
	    int min_pos;
		for(int i = 0; i < size-1; i++){
				min_pos = i; 
				for(int j = i+1; j < size; j++){
						if(arr[j] < arr[min_pos]){
						 	min_pos = j;
						}
				}
				temp = arr[min_pos];   // switching
				arr[min_pos] = arr[i];
				arr[i] = temp;
		}
}
int main(){
	const int size = 4;
	string arr[size];
	arr[0] = "aa";
	arr[1] = "cc";
	arr[2] = "ee";
	arr[3] = "bb";
	
	//generateRandomValues(arr,size);
	printAllValues(arr,size);
	selection_sort(arr,size);
	cout << "After" << endl;
	printAllValues(arr,size);

	return 0;
	
}

