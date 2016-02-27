#include "CellphoneHandler.h"
#include <iostream>
#include <string>

int menu();
void addPhone(CellphoneHandler* aCPH);
void removePhone(CellphoneHandler* aCPH);
void writeToFile(CellphoneHandler* aCPH);
void readFile(CellphoneHandler* aCPH);
void changePriceOnPhone(CellphoneHandler* aCPH);

int main(){
int option = 0;
cout << "Welcome to your personal phone Handler\nChoose your option:\n";
CellphoneHandler myCPHandler("myPhoneHandler", 1);
  while (option != 7) {
    option = menu();
    cin.ignore();
    switch (option){
      case 1:
            addPhone(&myCPHandler);
        break;
      case 2:
        removePhone(&myCPHandler);
        break;
      case 3:
        cout << myCPHandler.getPhonesToString();
        break;
      case 4:
        writeToFile(&myCPHandler);
        break;
      case 5:
        readFile(&myCPHandler);
        break;
      case 6:
        changePriceOnPhone(&myCPHandler);
        break;
      case 7:
        cout << "Exiting\n";
        break;
      }
  }
  return 0;
}

void addPhone(CellphoneHandler* aCPH){
    string name;
    int stock = 0;
    int price = 0;
    cout << "Enter model name: ";
        getline(cin,name);
        cout << "Enter stock: ";
        cin >> stock;
        cin.ignore();
        cout << "Enter price: ";
        cin >> price;
        cin.ignore();

        aCPH->addPhone(name, stock, price);
        cout << "Done.\n";
}
void removePhone(CellphoneHandler* aCPH){
    string name;
    cout << "Enter phone model name to remove: ";
        cin >> name;
        cin.ignore();
        aCPH->removePhone(name);
        cout << "Done.\n";
}
void writeToFile(CellphoneHandler* aCPH){
    string fileName;
    cout << "Enter file name to save: ";
        cin >> fileName;
        if(aCPH->writeToFile(fileName)){
        cout << "Done.\n";
        }
        else{
        cout << "Writing to file failed!\n";
        }

}
void readFile(CellphoneHandler* aCPH){
    string fileName;
    cout << "Enter file name to read: ";
        cin >> fileName;
        if(aCPH->readFromFile(fileName)){
            cout << "Done.\n";
        }
        else{
            cout << "Reading to file failed!\n";
        }
}
void changePriceOnPhone(CellphoneHandler* aCPH){
    int priceLimit, discount;
       cout << "Enter price limit: ";
        cin >> priceLimit;
        cout << "Enter discount (%): ";
        cin >> discount;
        cout << aCPH->changePrice(priceLimit, discount);
        cout << "Done.\n";
}
int menu(){
     int option = 0;
     cout << "1. Add a phone" << "\n2. Remove phone by name" << "\n3. Print all phones"
          << "\n4. Save to file" << "\n5. Read from file" << "\n6. Change price on phones"  << "\n7. Exit"  <<endl;
     cin >> option;
     return option;
}
