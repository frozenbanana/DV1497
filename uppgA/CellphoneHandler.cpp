#include "CellphoneHandler.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

CellphoneHandler::CellphoneHandler(){ // konsturktor standard
    this->name = "UNKNOWN";
    this->amountPhones = 0;
    this->capacity = 2;
    this->cellphones = new Cellphone*[this->capacity];
    for(int i = 0; i < this->capacity; i++){
        this->cellphones[i] = NULL;
    }
}
CellphoneHandler::CellphoneHandler(string name, int capacity){ //konstuktor
    this->name = name;
    this->capacity = capacity;
    this->amountPhones = 0;
    this->cellphones = new Cellphone*[this->capacity];
    for(int i = 0; i < this->capacity; i++){
        this->cellphones[i] = NULL;
    }
}
CellphoneHandler::~CellphoneHandler(){ // destr
    for(int i = 0; i < this->amountPhones; i++){
        delete this->cellphones[i];
    }
    delete [] this->cellphones; // tar bort pekaren till heapen också
}

CellphoneHandler::CellphoneHandler(CellphoneHandler const& orig){// cpy
  this->capacity = orig.capacity;
  this->amountPhones = orig.amountPhones;
  this->cellphones  = new Cellphone*[this->capacity];   // en ny array skapas
  for(int i = 0; i < this->amountPhones; i++){          // den gamla arrayen kopieras över
    this->cellphones[i] = new Cellphone(*orig.cellphones[i]);   //deep cpy
  }
}
void CellphoneHandler::setHandlerName(string name){
   this->name = name;
}
string CellphoneHandler::getHandlerName(){
  return this->name;
}
void CellphoneHandler::addPhone(string name, int stock, int price){
  if(exists(name) == -1){
    if(this->amountPhones == this->capacity){
      this->expand();
    }                                                                           // i kontruktorn
    this->cellphones[this->amountPhones++] = new Cellphone(name, stock, price); // sist tillgängliga nullpekare görs om till
  }                                                                         // en Cellphone-pekare (new) och sedan matas parameterna in
}
bool CellphoneHandler::removePhone(string name){
      bool flag = false;
      int index = exists(name); // om det finns i array spara undan indexet
      if(index != -1){
        delete this->cellphones[index];
        amountPhones--;
        this->cellphones[index] = this->cellphones[this->amountPhones];
        flag = true;
      }
      return flag;
}

void CellphoneHandler::expand(){
    this->capacity += this->capacity/2;
    Cellphone **temps = new Cellphone*[this->capacity]; //Ny array med större storlek
    for(int i = 0;i < this->amountPhones; i++){
        temps[i] = this->cellphones[i];     //Ny array pekars på gamla objekt
    }
    delete [] this->cellphones;               //gammal array försvinner
    this->cellphones = temps;           // orginalpekare pekas om till ny array
}
int CellphoneHandler::exists(string name){
    int ret = -1;
    for(int i = 0; i < this->amountPhones && ret == -1; i++){ // medans det finns objekt i arrayen och ingen har hittats
      if(this->cellphones[i]->getModelName() == name){
        ret = i;
      }
    }
  return ret;
}

void CellphoneHandler::changePrice(int priceLimit, double discount){
  int origPrice;
  int newPrice;
  double disc;
  for(int i = 0; i < this->amountPhones; i++){
      origPrice = this->cellphones[i]->getPrice(); // sparar orginal pris
    if(origPrice >= priceLimit){
      disc =  (double) 1 -(discount/100);          // räknar ut rabattfaktor
      newPrice = origPrice * disc;                 // sparar nya pricet
      this->cellphones[i]->setPrice(newPrice);     // byta till det nya priset
      cout << "New price for " << cellphones[i]->getModelName() << ": "
        << cellphones[i]->getPrice() << endl;
    }
  }
}
bool CellphoneHandler::writeToFile(string fileName){ //användaren ska ge namn på fil
    bool flag = false;
    ofstream phoneFile;
    phoneFile.open(fileName.c_str());
    if(phoneFile.is_open()){
 //     phoneFile << this->amountPhones << endl;// onödig pga readFromFile använder while loop
      for(int i = 0; i < this->amountPhones; i++){
        phoneFile << this->cellphones[i]->getModelName();
        phoneFile << ", " << this->cellphones[i]->getStock();
        phoneFile << ", " << this->cellphones[i]->getPrice() << endl;
      }
      flag = true;
      phoneFile.close();
    }
    return flag;
}
bool CellphoneHandler::readFromFile(string fileName){
    bool flag = false;
    string tempStr;
    string fileData = "";
    ifstream phoneFile;
    phoneFile.open(fileName.c_str());
    if(phoneFile.is_open()){
      flag = true;
      while(getline(phoneFile,tempStr)){
          fileData += tempStr;
          fileData += "\n";
      }
      cout << fileData << endl;
      phoneFile.close();
    }
    else{
      cout << "ERROR: File could not be opened." << endl;
    }
    return flag;
}

string CellphoneHandler::getPhonesToString(){
    string line = "";
    for(int i = 0; i < this->amountPhones; i++){
      line += this->cellphones[i]->toString();
    }
  return line;
}

