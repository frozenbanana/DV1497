#include "Cellphone.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Cellphone::Cellphone(){
    this->modelName = "UNKNOWN";
    this->stock = 0;
    this->price = 0;
}
Cellphone::Cellphone(string modelName, int stock, int price){
    this->modelName = modelName;
    this->stock = stock;
    this->price = price;
}
Cellphone& Cellphone::operator =(const Cellphone& orig){
	if(this != &orig){    	
		this->modelName = orig.modelName;
		this->stock = orig.stock;
		this->price = orig.price;
	}
	return *this; 	
}
Cellphone::~Cellphone(){};

void Cellphone::setModelName(string modelName){
    this->modelName = modelName;
}
void Cellphone::setStock(int stock){
    this->stock = stock;
}
void Cellphone::setPrice(int price){
    this->price = price;
}
string Cellphone::getModelName() const{
    return this->modelName;
}
int Cellphone::getStock() const{
    return this->stock;
}
int Cellphone::getPrice() const{
    return this->price;
}
string Cellphone::toString() const{
    stringstream ss;
    ss << this->modelName << endl << this->stock << endl << this->price << endl;
    return ss.str();
}
