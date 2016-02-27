#include "WoodHandler.h"
#include "Panel.h"
#include "Joist.h"
#include <iostream>
#include <string>
using namespace std;
bool addJoist(WoodHandler &aWoodHandler);
bool addPanel(WoodHandler &aWoodHandler);
bool removeWood(WoodHandler &aWoodHandler);
bool changeDimensionsOnWood(WoodHandler &aWoodHandler);
bool changePrimedOnPanel(WoodHandler &aWoodHandler);
int menu();

int main(){
      // test av konstruktor
	WoodHandler testhandler;
	testhandler.addPanel("10x20",20,"profile1", true);
	testhandler.addPanel("10x25",25,"profile2", false);
	//testhandler.addJoist("10x20", 20, "type");
	testhandler.addPanel("10x35",35,"profile3", false);
  cout << "From constructor: " << endl;
	cout << testhandler.printAllWood() << endl;
	/*// test av tilldelningsoperator
	WoodHandler testhandler2;
	testhandler2.addJoist("10x20", 20, "type");
	testhandler2 = testhandler;
    cout << "From assignment operator constructor: "<< endl;
	cout << testhandler2.printAllWood() << endl;
  // test av cpy konstrukor
  WoodHandler testhandler3=testhandler;
	cout << "From cpy constructor: " << endl;
	cout << testhandler3.printAllWood() << endl;*/
int option = 0;
cout << "Welcome to the WoodHandler\nChoose your option:\n";
WoodHandler aWoodHandler;
WoodHandler &whR = aWoodHandler; // reference till aWoodHandler som används av funktionerna i main
  while (option != 8) {
    option = menu();
    cin.ignore();
    switch (option){
      case 1:
		   addJoist(whR);
        break;
      case 2:
	    	addPanel(whR);
        break;
      case 3:
			cout << aWoodHandler.printAllWood();
        break;
      case 4:
            cout << aWoodHandler.printAllPanel();
        break;
      case 5:
			cout << aWoodHandler.printAllJoist();
        break;
      case 6:
			removeWood(whR);
        break;
      case 7:
            changePrimedOnPanel(whR);
        break;
      case 8:
        cout << "Exiting\n";
        break;
      }
  }
  return 0;
}


int menu(){
  int option = 0;
  cout << "1. Add joist" << "\n2. Add panel" << "\n3. Print all your inventory"
       << "\n4. Print your panels" << "\n5. Print your joists" << "\n6. Remove wood"  << "\n7. Change priming on panel"<<"\n8. Exit"  <<endl;
  cin >> option;
  return option;
}
bool removeWood(WoodHandler &aWoodHandler){
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
		if (flagJ || flagP){
                cout << "Wood has been removed." << endl;
				ret = true;
		}
		else{
            cout << "Nothing removed." << endl;
		}
		return ret;
}
/* Frågar användaren om parametrar till woodhandler.addJoist funktion */
bool addJoist(WoodHandler &aWoodHandler){
		string dimensions;
		int meterPrice;
		string type;
		bool flag = false;
		cout << "Type in the dimensions of the wood that you want to add: ";
		cin >> dimensions;
		cin.ignore();
		cout << "Type in the price/meter of the wood that you want to add: ";
		cin >> meterPrice;
		cout << "Type in which type: ";
		cin >> type;
		cin.ignore();

        flag = aWoodHandler.addJoist(dimensions,meterPrice,type);
		if(flag == true){
            cout << aWoodHandler.printAllJoist();
            cout << "joist added." << endl;
		}
		return flag;

}
/* frågar användaren om parameterar till woodhandler.addPanel funktionen */
bool addPanel(WoodHandler &aWoodHandler){
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
		cout << "Type in which profile: ";
		cin >> profile;
		cin.ignore();
		cout << "Primed?(yes/no): ";
		cin >> answerPrimed;
		cin.ignore();
		if(answerPrimed == "yes"){
				primed = true;
		}
		flag = aWoodHandler.addPanel(dimensions, meterPrice, profile, primed);
		if(flag == true){
            cout << "panel added." << endl;
		}
		else{
            cout << "Error." << endl;
		}

		return flag;
}

/* Ändra egenskapen grundmålad för en panel givet dimension och profil */
bool changePrimedOnPanel(WoodHandler &aWoodHandler){
		bool flag = false;
		string dimensions;
		string profile;
		string change;
		cout << "Type in the dimensions of the panel you want to change priming for: ";
		cin >> dimensions;
		cin.ignore();
		cout << "Type in which profile: ";
		cin >> profile;
		cin.ignore();
		for(int i = 0; i < aWoodHandler.getNrOfWood();i++){
            if(aWoodHandler.searchPanel(i, dimensions,profile)){
                flag = true;
                if(aWoodHandler.decideIfPrimed(i) == true){
                    cout << "This panel is primed." << endl;
                }
                else{
                    cout << "This panel is not primed" << endl;
                }
            }
            cout << "Do you want to have the panel primed? (Yes/no) ";
            cin >> change;
            cin.ignore();
            if(change == "yes"){
                aWoodHandler.makePanelIsPrimed(i,true);
                cout << "Done." << endl;
            }
            else{
                aWoodHandler.makePanelIsPrimed(i,false);
                cout << "Done." << endl;
            }
		}
		return flag;
}

