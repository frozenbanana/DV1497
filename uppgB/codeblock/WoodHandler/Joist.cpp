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
				Wood::operator=(orig);      //origanel skickas vidare till wood för basmedlemmar
				this->type=type;
		}
		return *this;
}

string Joist::toStringSpecific() const{
		stringstream ss;
		ss <<"Type: "<< this->type << endl;
		return ss.str();
}
void Joist::setType(string type){
		this->type = type;
}
string Joist::getType()const{
		return this->type;
}
Joist::~Joist(){}

Wood* Joist::clone()const{      // används vid cpy konstuktor och assignment overload så man slipper typecasta
    return new Joist(*this);
}

