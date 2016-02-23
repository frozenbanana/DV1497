#include "WoodHandler.h"
#include "Panel.h"
#include "Joist.h"
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/* lägger till panel */
bool WoodHandler::addPanel(string dimensions, int meterPrice, string profile, bool primed){
		bool flag = false;
		if((this->capacity - this->nrOfWood) < 2){       // skapar större array om limit är nådd
            expand();
        }
		if(this->nrOfWood < this->capacity)         // annars skapa ny Panel på index [nrOfWood] sedan ++
		{
				this->woods[this->nrOfWood++] = new Panel(dimensions,meterPrice,profile,primed);
				flag = true;
		}
		return flag;
}
/* Lägger till regel */
bool WoodHandler::addJoist(string dimensions, int meterPrice, string type){
		bool flag = false;
        if((this->capacity - this->nrOfWood) < 2){                           // om det inte finns plats så gör arrayen större
            expand();
		}
		if(this->nrOfWood < this->capacity){                            // annars skapa objekt på index [nrOfWood]
				this->woods[nrOfWood++] = new Joist(dimensions, meterPrice, type);
				flag = true;
		}
		return flag;
}
 /*Tar bort ett panel objekt */
bool WoodHandler::removePanel(string dimensions, int meterPrice){
		bool flag = false;
		Panel* panelptr = nullptr;                                                      //pekare för att jämföra
		for (int i = 0; i < this->nrOfWood; i++){
			panelptr = dynamic_cast<Panel*>(woods[i]);                                  //jämför om det är samma subklass
			if (panelptr != nullptr && this->woods[i]->getDimensions() == dimensions && this->woods[i]->getMeterPrice() == meterPrice){
				delete woods[i];                                                        // om alla parametrar stämmer så tar vi bort den
				woods[i] = woods[--nrOfWood];                                           // fyller hålet med den sista i arrayen
				flag = true;
		}
	}
	return flag;
}
/* Tar bort en regel */
bool WoodHandler::removeJoist(string dimensions, int meterPrice){
	    	bool flag = false;                                       // flag för att kolla om allt gick bra
		Joist* joistptr = nullptr;                                      // joistpekare för att kolla om woods[i] är joist
		for (int i = 0; i < this->nrOfWood; i++){                       // tittar på alla
			joistptr = dynamic_cast<Joist*>(woods[i]);                  // försöker dynamic casta
			if (joistptr != nullptr && this->woods[i]->getDimensions() == dimensions && this->woods[i]->getMeterPrice() == meterPrice){
				delete woods[i];                                        // om det stämmer så tar vi bort den
				woods[i] = woods[--nrOfWood];                           // och fyller hålet med den sista i arrayen
				flag = true;
		}
	}
	return flag;
}
WoodHandler& WoodHandler::WoodHandler::operator=(const WoodHandler &orig){
		if(this != &orig){                                      // kolla om det inte är a=a
				for(int i = 0; i < this->nrOfWood; i++){        // tar bort varje objekt i array
						delete this->woods[i];
				}
				this->nrOfWood = orig.nrOfWood;                 //sätter nya variabler från orig
				this->capacity = orig.capacity;
				this->woods = new Wood*[this->capacity];        //ny array med orig's capacity
		}
		for(int i = 0; i < this->nrOfWood; i++){
				this->woods[i] = orig.woods[i]->clone(); // då skapar den ett objekt av rätt subobj pga clone
                //cout << this->woods[i]->toString();
		}
		return *this; // så man kan skriva a=b=c
}
/* cpy konstruktor */
WoodHandler::WoodHandler(const WoodHandler &orig){
		this->nrOfWood = orig.nrOfWood;         //sätter samma variabler (shallow cpy)
		this->capacity = orig.capacity;
		this->woods = new Wood*[this->capacity];    //skapar också en array med samma storlek
		for (int i = 0; i < this->nrOfWood; i++){
				this->woods[i] = orig.woods[i]->clone();    // kopierar, clone avgör vilket objekt det ska vara
		}
	}

WoodHandler::WoodHandler(){
	this->nrOfWood = 0;
	this->capacity = 2;
	this->woods = new Wood*[this->capacity];
	for(int i = 0; i < this->capacity; i++){
			woods[i] = nullptr;
	}
}
WoodHandler::WoodHandler(int capacity){
	this->nrOfWood = 0;
	this->capacity = capacity;
	this->woods = new Wood*[this->capacity];
	for(int i; i < this->capacity; i++){
			woods[i] = nullptr;
	}
}
WoodHandler::~WoodHandler(){
		for(int i = 0; i < this->capacity; i++){
				delete this->woods[i];
		}
		delete [] this->woods;
}
void WoodHandler::setCapacity(int capacity){
		this->capacity = capacity;
}
int WoodHandler::getNrOfWood(){
		return this->nrOfWood;
}
int WoodHandler::getNrOfPanels(){
	int nrOfPanels = 0;
	Panel* panelptr = nullptr;                  // skapar en panelpekare för testa array
	for (int i = 0; i < this->nrOfWood; i++){
		panelptr = dynamic_cast<Panel*>(woods[i]);  // här testar vi med dynamic_cast om woods[i] är av subtyp panel
		if (panelptr != nullptr){
			nrOfPanels++;                           // räkna
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
/* Avgör vilken subklass en wood är */
string WoodHandler::decideDerived(Wood* unknown) const{
    string answer = "UNKNOWN";
    Joist* joistTester = nullptr;
    Panel* panelTester = nullptr;

    joistTester = dynamic_cast<Joist*>(unknown); // testar unknown om den är Joist
    panelTester = dynamic_cast<Panel*>(unknown); // testar unknown om den är Panel
    if(unknown == joistTester){
        answer = "joist";
    }
    else if(unknown == panelTester){
        answer = "panel";
    }
    return answer;
}
/* Söker igenom alla panels i arrayen. returnerar true om den hitta rätt panel*/
bool WoodHandler::searchPanel(int index, string dimensions, string profile){
bool flag = false;
    Panel* panelptr;
    if(this->decideDerived(this->woods[index]) == "panel"){
        if(this->woods[index]->getDimensions() == dimensions){
            panelptr = dynamic_cast<Panel*>(this->woods[index]); // dynamic cast för att nå Panel funktion
            if(panelptr->getProfile() == profile){
            flag = true;
            }
        }
    }
    return flag;
}
/* ändrar grundmålad på en panelsobjekt */
bool WoodHandler::makePanelIsPrimed(int index, bool primed){
    bool flag=false;
    Panel* panelptr;
    panelptr = dynamic_cast<Panel*>(this->woods[index]);
    if(panelptr != nullptr){
        panelptr->setPrimed(primed);
        flag = true;
    }
    return flag;
}
/* kolla om panelobjekt är grundmålad */
bool WoodHandler::decideIfPrimed(int index){
                bool flag = false;
                Panel* panelptr = nullptr;
                panelptr = dynamic_cast<Panel*>(this->woods[index]);  // jämför
                if(panelptr != nullptr && panelptr->getPrimed() == true){ // om det stämmer och den är grundmålad sätt flag= true
                    flag = true;
                }
                else{
                    flag = false;
                }
        return flag;
}
/* printar alla objekt i array */
string WoodHandler::printAllWood() const{

	stringstream ss;
	for (int i = 0; i < this->nrOfWood; i++){{
		ss << this->woods[i]->toString();   // varje objekt kallar på sin toString()
	}

 }
	return ss.str();
}
string WoodHandler::printAllPanel(){
    Panel* panelptr = nullptr;
    stringstream ss;
    for(int i = 0; i < this->getNrOfWood(); i++){
        panelptr = dynamic_cast<Panel*>(this->woods[i]);
        if(panelptr != nullptr){
            ss << this->woods[i]->toString();
        }
    }
    return ss.str();
}
/* printar alla reglar (joist) */
string WoodHandler::printAllJoist(){
    Joist* joistptr = nullptr;
    stringstream ss;
    for(int i = 0; i < this->getNrOfWood(); i++){
        joistptr = dynamic_cast<Joist*>(this->woods[i]);
        if(joistptr != nullptr){
            ss << this->woods[i]->toString();
        }
    }
    return ss.str();
}
void WoodHandler::expand(){
	this->capacity += 5;
	cout << "it expands:" << this->capacity << endl;								// Öka capacity
	Wood** tempArray = new Wood*[this->capacity];	    // Skapa temporär array

	for (int i = 0; i < this->nrOfWood; i++) {		// Kopiera tidigare objekt till ny array
		tempArray[i] = this->woods[i];				//
	}													//
	for (int i = 0; i < this->nrOfWood; i++) {		// Avallokera objekt i tidigare array
		delete this->woods[i];						//
	}
	delete[] this->woods;								// Avallokera tidigare array
	this->woods = tempArray;							// Peka om tidigare array till ny array
}