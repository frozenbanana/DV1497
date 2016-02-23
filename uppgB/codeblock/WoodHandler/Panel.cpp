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
Panel::Panel(const Panel &orig): Wood(orig){ // cpy konstrukor för panel
		this->profile = orig.profile;
		this->primed = orig.primed;
}
Panel& Panel::operator =(const Panel &orig){ // assignment overload
		if(this != &orig){
				Wood::operator=(orig); // skickar referensen till woods assign overload för att låta den ta basmedlemmarna
				this->profile = orig.profile;
				this->primed = orig.primed;
		}
		return *this;
}
/* skickar ut sina unika medlemmar */
string Panel::toStringSpecific() const{
		stringstream ss;
		ss << "Profile: " << this->profile << endl;
		ss << "Primed: ";
		if(this->primed){
            ss << "Yes" << endl;
		}
		else{
            ss << "No" << endl;
		}
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
bool Panel::getPrimed(){
		return this->primed;
}
Panel::~Panel(){}
/* används vid cpy konstruktor för att slippa dynamicasta */
Wood* Panel::clone()const{
    return new Panel(*this);
}

