#include "WoodHandler.h"
#include <iostream>
#include <string>
using namespace std;
int menu();

int main(){
int priceLimit;
int stock;
int price;
int option = 0;
cout << "Welcome to the WoodHandler\nChoose your option:\n";
WoodHandler aWoodHandler;
  while (option != 7) {
    option = menu();
    cin.ignore();
    switch (option){
      case 1:
			  aWoodHandler.addJoist();
        break;
      case 2:
			aWoodHandler.addPanel();
        break;
      case 3:
			aWoodHandler.printAll();
        break;
      case 4:
			removeWood(aWoodHandler);
        break;
      case 5:
        break;
      case 6:
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
       << "\n4. Remove wood" << "\n5. Change price on phones"  << "\n6. Exit"  <<endl;
  cin >> option;
  return option;
}
bool removeWood(WoodHandler aWoodHandler){
		bool ret;
		bool flagJ;
		bool flagP;
		string dimensions;
		int meterPrice;
		cout << "Type in the dimensions of the wood that you want to remove: ";
		getline(cin,dimensions);
		cout << "Type in the price/meter of the wood that you want to remove: ";
		cin >> meterPrice;

		flagJ = aWoodHandler.removePanel(dimensions, meterPrice);
		flagP = aWoodHandler.removeJoist(dimensions, meterPrice);
		if (flagJ && flagP){
				ret = true;
		}
		return ret;
}
