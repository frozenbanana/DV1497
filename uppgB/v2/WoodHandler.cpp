#include "WoodHandler.h"
#include "Panel.h"
#include "Joist.h"
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool WoodHandler::addPanel(string dimensions, int meterPrice, string profile, bool primed){
		bool flag = false;
		if(this->nrOfWood < this->capacity)
		{
				this->woods[nrOfWood++] = new Panel(dimensions,meterPrice,profile,primed);
				flag = true;
		}
		return flag;
}
bool WoodHandler::addJoist(string dimensions, int meterPrice, string type){
		bool flag = false;
		if(this->nrOfWood < this->capacity){
				this->woods[nrOfWood] = new Joist(dimensions, meterPrice, type);
				flag = true;
		}
		return flag;
}
bool WoodHandler::removePanel(string dimensions, int meterPrice){
		bool flag = false;
		Panel* panelptr = nullptr;
		for (int i = 0; i < this->nrOfWood; i++){
			panelptr = dynamic_cast<Panel*>(woods[i]);
			if (panelptr != nullptr && this->woods[i]->getDimensions() == dimensions && this->woods[i]->getMeterPrice() == meterPrice){
				delete woods[i];
				woods[i] = woods[--nrOfWood];
				flag = true;
		}
	}
	return flag;
}
bool WoodHandler::removeJoist(string dimensions, int meterPrice){
	    	bool flag = false;
		Joist* joistptr = nullptr;
		for (int i = 0; i < this->nrOfWood; i++){
			joistptr = dynamic_cast<Joist*>(woods[i]);
			if (joistptr != nullptr && this->woods[i]->getDimensions() == dimensions && this->woods[i]->getMeterPrice() == meterPrice){
				delete woods[i];
				woods[i] = woods[--nrOfWood];
				flag = true;
		}
	}
	return flag;	
}
WoodHandler& WoodHandler::WoodHandler::operator=(const WoodHandler &orig){ //tveksamt
		if(this != &orig){
				for(int i = 0; i < this->nrOfWood; i++){
						delete this->woods[i];
				}
				this->nrOfWood = orig.nrOfWood;
				this->capacity = orig.capacity;
				this->woods = new Wood*[this->capacity];
		}
		for(int i = 0; i < this->nrOfWood; i++){
				if (typeid(*orig.woods[i]) == typeid(*Panel) orig.woods[i]){
				this->woods[i] = new Panel(*((*Panel)orig.woods[i]));
			}
			else{
				this->woods[i] = new Joist(*((*Joist)orig.woods[i]));
			}
		}
		return *this;
}
WoodHandler::WoodHandler(int capacity){
		this->capacity = capacity;
}
WoodHandler::WoodHandler(const WoodHandler &orig){ // tveksamt
		this->nrOfWood = orig.nrOfWood;
		this->capacity = orig.capacity;
		this->woods = new Wood*[this->capacity];
		for (int i = 0; i < this->nrOfWood; i++){
			if (typeid(*orig.woods[i]) == typeid(*Panel) orig.woods[i]){
				this->woods[i] = new Panel(*((*Panel)orig.woods[i]));
			}
			else{
				this->woods[i] = new Joist(*((*Joist)orig.woods[i]));
			}
		}
	}
}
WoodHandler::WoodHandler(){
	this->nrOfWood = 0;
	this->capacity = 2;	
	this->woods = new *Wood[this->capacity];
	for(int i = 0; i < this->capacity; i++){
			woods[i] = nullptr;
	}
}
WoodHandler::WoodHandler(int capacity){
	this->nrOfWood = 0;
	this->capacity = capacity;	
	this->woods = new *Wood[this->capacity];
	for(int i; i < this->capacity; i++){
			woods[i] = nullptr;
	}
}
WoodHandler::~Woodhandler(){
		for(int i = 0; i < this->capacity; i++){
				delete this->woods[i];
		}
		delete [] this->woods;
}
void WoodHandler::setCapacity(int capacity){
		this->capacity = capacity;
}
int WoodHandler::getNrOfWood(){
		return this->nrOfwood;
}
int WoodHandler::getNrOfPanels(){
	int nrOfPanels = 0;
	Panel* panelptr = nullptr;
	for (int i = 0; i < this->nrOfWood; i++){
		panelptr = dynamic_cast<Panel*>(woods[i]);
		if (panelptr != nullptr){
			nrOfPanels++;
		}
	}
	return nrOfPanels;

}
int WoodHandler::getNrOfJoists(){
	int nrOfJoists = 0;
	Joist* joistptr = nullptr;
	for (int i = 0; i < this->nrOfWood; i++){
		joistptr = dynamic_cast<Joist*>(woods[i]);
		if (joistptr != nullptr){
			nrOfJoists++;
		}
	}
	return nrOfJoists;
}
void WoodHandler::printAllWood() const{
	for (int i = 0; i < this->nrOfWood; i++){
		this->woods[i]->toString();
	}
}


