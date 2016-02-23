#include "Wood.h"
#include <iostream>
#include <sstream>
#include <string>

Wood::Wood(const Wood &orig){
	this->dimensions = orig.dimensions;
	this->meterPrice = orig.meterPrice;
}
Wood& Wood::operator =(const Wood& orig){
		if(this != &orig){
				this->dimensions = orig.dimensions;
				this->meterPrice = orig.meterPrice;
		}
		return *this;
}
Wood::~Wood(){}
string Wood::toStringSpecific(); // förklara varför detta behövs
string Wood::getDimensons(){
		return this->dimensions;
}
Wood::Wood(){
		this->dimensions = "Unkown";
		this->meterPrice = 0;
}
Wood::Wood(string dimensions, int meterPrice){
		this->dimensions = dimensions;
		this->meterPrice = meterPrice;
}
int Wood::getMeterPrice() {
		return this->meterPrice;
}
string Wood::toString(){
		stringstream ss;
		ss << this->dimensions << endl;
		ss << this->meterPrice << endl;//knasigt
		return toStringSpecific(); // fÅ rätt pÅ det här
}  
void Wood::setDimensons(string dimensions){
		this->dimensions = dimensions;
}
void Wood::setMeterPrice(int meterPrice){
		this->meterPrice = meterPrice;
}


