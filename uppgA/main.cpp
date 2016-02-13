#include "CellphoneHandler.h"
#include <iostream>
#include <string>

int menu();

int main(){
string name;
string received;
string fileName;
int priceLimit;
double discount;
int stock;
int price;
int option = 0;
cout << "Welcome to your personal phone Handler\nChoose your option:\n";
CellphoneHandler myCPHandler("myPhoneHandler", 1);
  while (option != 7) {
    option = menu();
    cin.ignore();
    switch (option){
      case 1:
        cout << "Enter model name: ";
        getline(cin,name);
        cout << "Enter stock: ";
        cin >> stock;
        cin.ignore();
        cout << "Enter price: ";
        cin >> price;
        cin.ignore();

        myCPHandler.addPhone(name, stock, price);
        cout << "Done.\n";
        break;
      case 2:
        cout << "Enter phone model name to remove: ";
        cin >> name;
        cin.ignore();
        myCPHandler.removePhone(name);
        cout << "Done.\n";
        break;
      case 3:
        received = myCPHandler.getPhonesToString();
        cout << received;
        break;
      case 4:
          cout << "Enter file name to save: ";
          cin >> fileName;
        if(myCPHandler.writeToFile(fileName)){
          cout << "Done.\n";
          }
        else{
          cout << "Writing to file failed!\n";
        }
        break;
      case 5:
          cout << "Enter file name to read: ";
          cin >> fileName;
        if(myCPHandler.readFromFile(fileName)){
          cout << "Done.\n";
          }
        else{
          cout << "Reading to file failed!\n";
        }
        break;
      case 6:
        cout << "Enter price limit: ";
        cin >> priceLimit;
        cout << "Enter discount (%): ";
        cin >> discount;
        myCPHandler.changePrice(priceLimit, discount);
        cout << "Done.\n";
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
  cout << "1. Add a phone" << "\n2. Remove phone by name" << "\n3. Print all phones"
       << "\n4. Save to file" << "\n5. Read from file" << "\n6. Change price on phones"  << "\n7. Exit"  <<endl;
  cin >> option;
  return option;
}
