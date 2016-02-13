#include "Cellphone.h"
#include <iostream>
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
string Cellphone::getModelName(){
    return this->modelName;
}
int Cellphone::getStock(){
    return this->stock;
}
int Cellphone::getPrice(){
    return this->price;
}
string Cellphone::toString(){
    string line = "";
    line += this->modelName + ", " + to_string(this->stock) + "st, " + to_string(this->price) + ":-\n";
    return line;
}
