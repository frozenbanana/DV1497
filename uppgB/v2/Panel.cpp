#include <iostream>
#include <sstream>
#include <string>
#include "Panel.h"
#include "Wood.h"
using namespace std;


Panel::Panel(string dimensions, int meterPrice, string profile, bool primed): Wood(dimensions, meterPrice){
		this->profile = profile;
		this->primed = primed;
}
Panel::Panel(const Panel &orig): Wood(orig){ // cpy obj?
		this->profile = profile;
		this->primed = primed;
}
Panel& Panel::operator =(const Panel &orig){// assignment overload
		if(this != &orig){
				Wood::operator=(orig); // vad händer här?
				this->profile = profile;
				this->primed = primed;
		}
		return *this;
}

string Panel::toStringSpecific() const{
		stringstream ss;
		ss << this->profile << ", ";
		ss << this->primed << ", ";
		return ss.str();
}
void Panel::setProfile(string profile){
		this->profile = profile;
}
string Panel::getProfile(){
		return this->profile;
}
void Panel::setPrimed(bool primed){
		this->primed=primed;
}
bool getPrimed(){
		return this->primed;
}
Panel::~Panel(){}

