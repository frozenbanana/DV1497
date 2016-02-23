#pragma once
#include <iostream>
#include <string>

template <typename T>
class Vector{
		private:
				T *items;
				int capacity;
				int capacityIncrement;
				int nrOfItems;
				void expand();
		public:
				Vector();
				Vector(int capacity);
				Vector(int capacity, int capacityIncrement);
				~Vector();
				Vector(const Vector<T> &orig);
				Vector& operator=(const Vector<T> &orig){
				Vector addAt(int index, T item) throw(...);
};

template <typename T>
Vector<T>::Vector() {
		this->capacity = 10;
		this->capacityIncrement = 10;
		this->nrOfItems = 0;
		this->items = new T[this->capacity];
}
template <typename T>
Vector<T>::Vector(int capacity){
		this->capacity = capacity;
		this->capacityIncrement = 10;
		this->nrOfItems = 0;
		this->items = new T[this->capacity];
}
template <typename T>
Vector<T>::Vector(int capacity, int capacityIncrement){
		this->capacity = capacity;
		this->capacityIncrement = capacityIncrement;
		this->nrOfItems = 0;
		this->items = new T[this->capacity];
}
template <typename T>
Vector<T>::~Vector(){
		delete [] this->items;
}
template <typename T>
Vector<T>::Vector(const Vector<T> &orig){
		this->capacity = orig.capacity;
		this->capacityIncrement = orig.capacityIncrement;
		this->nrOfItems = orig.nrOfItems;
		this->items = new T[this->capacity];
		for(int i = 0; i < this->nrOfItems;i++){
				this->items[i] = orig.items[i];
		}
}
template <typename T>
Vector<T>&Vector<T>::operator=(const Vector<T> &orig){
		if(this != &orig){
				delete [] this->items;
				this->capacity = orig.capacity;
				this->capacityIncrement = orig.capacity;
				this->nrOfItems = orig.nrOfItems;
		}
		for(int i = 0; i < this->nrOfItems; i++){
			this->items = new T[this-capacity];
		}
		return *this;	
}
template <typename T>
void Vector<T>::expand(){
		T* temp = new T[this->capacity + this->capacityIncrement];
		for(int i = 0; i < this->nrOfItems;i++){
				temp[i] = items[i];
		}
		delete this->items;
		this->items = temp;
}
template <typename T>
void Vector<T>::addAt(int index, T item) throw(...){
		if(index > this->nrOfitems){
				throw "not allowed position!";
		}
		if(this->nrOfitems == this->capacity){ // if array is full
			this->expand();
			this->items[this->nrOfitems++] = this->items[index]; // moves the occupied index to the last place
			this->items[index] = item; // and then put the item on index
		}
}

