#include "WoodHandler.h"
#include <iostream>
#include <string>

bool addJoist(WoodHandler aWoodHandler);
bool addPanel(WoodHandler aWoodHandler);
void printAll(WoodHandler aWoodHandler);
bool removeWood(WoodHandler aWoodHandler);
bool changeDimensionsOnWood(WoodHandler aWoodHandler);
bool changePriceOnWood(WoodHandler aWoodHandler);
int menu();
int main(){
int option = 0;
cout << "Welcome to the WoodHandler\nChoose your option:\n";
WoodHandler aWoodHandler;
  while (option != 7) {
    option = menu();
    cin.ignore();
    switch (option){
      case 1:
		    addJoist(aWoodHandler);
        break;
      case 2:
	    	addPanel(aWoodHandler);
        break;
      case 3:
			printAll(aWoodHandler);
        break;
      case 4:
			removeWood(aWoodHandler);
        break;
      case 5:
			changeDimensionsOnWood(aWoodHandler);
        break;
      case 6:
			changePriceOnWood(aWoodHandler);
        break;
      case 7:
        cout << "Exiting\n";
        break;
      }
  }
  return 0;
}


int menu(){
  int option = 0;
  cout << "1. Add joist" << "\n2. Add panel" << "\n3. Print your inventory"
       << "\n4. Remove wood" << "\n5. Change dimensions on wood" << "\n6. Change price/meter on wood"  << "\n7. Exit"  <<endl;
  cin >> option;
  return option;
}
bool removeWood(WoodHandler aWoodHandler){
		bool ret = false;
		bool flagJ;
		bool flagP;
		string dimensions;
		int meterPrice;
		cout << "Type in the dimensions of the wood that you want to remove: ";
		cin >> dimensions;
		cin.ignore();
		cout << "Type in the price/meter of the wood that you want to remove: ";
		cin >> meterPrice;

		flagJ = aWoodHandler.removePanel(dimensions, meterPrice);
		flagP = aWoodHandler.removeJoist(dimensions, meterPrice);
		if (flagJ && flagP){
				ret = true;
		}
		return ret;
}

bool addJoist(WoodHandler aWoodHandler){
		string dimensions;
		int meterPrice;
		string type;
		bool flag = false;
		cout << "Type in the dimensions of the wood that you want to add: ";
		cin >> dimensions;
		cin.ignore();
		cout << "Type in the price/meter of the wood that you want to add: ";
		cin >> meterPrice;
		cout << "Type in which type ";
		cin >> type;
		cin.ignore();

		flag = aWoodHandler.addJoist(dimensions,meterPrice,type);
		return flag;

}
bool addPanel(WoodHandler aWoodHandler){
	
		string dimensions;
		int meterPrice;
		string profile;
		string answerPrimed;
		bool primed = false;
		bool flag = false;
		cout << "Type in the dimensions of the panel that you want to add: ";
		cin >> dimensions;
		cin.ignore();
		cout << "Type in the price/meter of the panel that you want to add: ";
		cin >> meterPrice;
		cout << "Type in which profile ";
		cin >> profile;
		cin.ignore();
		cout << "Primed?(yes/no) ";
		cin >> primed;
		if(answerPrimed == "yes"){
				primed = true;
		}
		flag = aWoodHandler.addPanel(dimensions, meterPrice, profile, primed);

		return flag;
}
bool changePrimedOnPanel(WoodHandler aWoodHandler){
		bool flag = false;
		string dimensions;
		string profile;
		cout << "Type in the dimensions of the panel you want to change priming for ";
		cin >> dimensions;
		cin.ignore();
		cout << "Type in which profile ";
		cin >> profile;
		cin.ignore();

		
}
