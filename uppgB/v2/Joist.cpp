#include <iostream>
#include <sstream>
#include <string>
#include "Joist.h"
#include "Wood.h"
using namespace std;


Joist::Joist(string dimensions, int meterPrice, string type): Wood(dimensions, meterPrice){
		this->type = type;
}
Joist::Joist(const Joist &orig): Wood(orig){ // cpy obj?
		this->type = type;
}
Joist& Joist::operator =(const Joist &orig){// assignment overload
		if(this != &orig){
				Wood::operator=(orig); // vad händer här?
				this->type=type;
		}
		return *this;
}

string Joist::toStringSpecific() const{
		stringstream ss;
		ss << this->type;
		return ss.str();
}
void Joist::setType(string type){
		this->type = type;
}
string Joist::getType(){
		return this->type;
}
Joist::~Joist(){}

