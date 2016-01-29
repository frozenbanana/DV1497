#include <iostream>
#include <string>

using namespace std;

int main(){

  string name;
  int age;
  string city;
  cout << "ange ditt namn:";
  getline(cin, name);
  cout << "ange din ålder:";
  cin >> age;
  cin.ignore();
  cout << "Stad:";
  getline(cin, city);
  cout << name << "," << age;
  cout << "\n" << city << endl;

  string str3 = name + city;
  cout << str3 << endl;

  cout << str3.length() << endl;
  cout << str3.find("Ma") << endl;
  cout << str3.compare("HenryMalmöa§") << endl;
  return 0;
 }
