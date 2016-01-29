#include "Friend.h"
#include "FriendBook.h"
#include <iostream>
#include <string>

// 8, 12-17 i classer och obj
// mer teori: 18-25
using namespace std;

int main(){
	FriendBook fb;
  int count;
  string name;
  string adress;
  string birth;
  string email;
  string phoneNr;

  cout << "How many friends do you want to add?\n";
  cin >> count;
  cin.ignore();
  fb.setName("test");
	fb.addFriend("Henry", "Ärenprisgatan 22D", "199209243113", "hej@gmail.com", "19813913");
  fb.addFriend("Eric", "Kvarngatan 6D", "199203892", "kalle@bögporr.se","1231241234");
  for (int i = 0; i < count ; i++) {
    cout << "Friend add nr: " << i+1 << endl;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter adress: ";
    getline(cin, adress);
    cout << "Enter birth: ";
    getline(cin, birth);
    cout << "Enter email: ";
    getline(cin, email);
    cout << "Enter phoneNr: ";
    getline(cin, phoneNr);
    fb.addFriend(name,adress, birth, email, phoneNr);
  }
  fb.printAll();
  fb.saveAll();
	return 0;


}
