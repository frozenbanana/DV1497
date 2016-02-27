#include <iostream>
#include <string>
using namespace std;

int main(){
  string efternamn;
  string fornamn;

  std::cout << "Ditt fornamn? ";
  std::cin >> fornamn;
  cin.ignore();
  std::cout << "Ditt efternamn? ";
  std::cin >> efternamn;

  std::cout << "Hej " << fornamn + " " + efternamn << ", Välkommen till programmeringskursen!" <<  std::endl;
  return 0;
 }
