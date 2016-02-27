/*
1. Skapa ett objekt av typen CellPhoneHandler (låt startkapaciteten vara 2).
2. Lägg in 2 mobiltelefoner.
3. Skriv ut de strängar som erhålls i arrayen som medlemsfunktionen för CellPhoneHandler-objektet
fyller i
4. Lägg till ytterligare en mobiltelefon (vilket ska medföra att CellPhoneHandler-objektets array
    expanderas). Skriv ut de strängar som erhålls i arrayen som medlemsfunktionen för CellPhoneHandler-
objektet fyller i.
5. Försök ta bort en mobiltelefon som inte finns inlagd och kontrollera att ingen borttagning gjordes
samt generera en utskrift av detta.
6. Ta bort en mobiltelefon som finns inlagd och kontrollera att borttagningen genomförts.
7. Tag bort de resterande 2 mobiltelefonerna från CellPhoneHandler-objektet och kontrollera att det
därefter inte innehåller några mobiltelefoner.
8. Lägg till 2 nya mobiltelefoner till CellPhoneHandler-objektet och kontrollera att dessa finns inlagda.
9. Testa på lämpligt sätt kopieringskonstruktor(copykonstruktor) och tilldelningsoperator.
Avsluta programmet och kontrollera slutligen att inga minnesläckor upptäckts!
*/
#include "CellphoneHandler.h"
#include <iostream>
#include <string>

int main(){
  CellphoneHandler aCPHandler; // 1
  aCPHandler.addPhone("aPhone",2,1400);
  aCPHandler.addPhone("anotherPhone",2,1600);//2
  cout << "3. \n" << aCPHandler.getPhonesToString();//3
  aCPHandler.addPhone("extraPhone",2,1800);//4

  aCPHandler.removePhone("phone");//5
  cout << "5 (försökt ta bort med fel namn). \n"  << aCPHandler.getPhonesToString();

  aCPHandler.removePhone("anotherPhone");//6
 cout << "6. (tagit bort anotherPhone)\n"  << aCPHandler.getPhonesToString();
  aCPHandler.removePhone("aPhone");
  aCPHandler.removePhone("extraPhone");
   cout << "7. (tagit bort resten) \n"  << aCPHandler.getPhonesToString();//7

  aCPHandler.addPhone("newPhone",6,10000);
  aCPHandler.addPhone("new2Phone",7,12500);
  cout << "8.(lägger till två nya) \n"  << aCPHandler.getPhonesToString();//8

  cout << "Test av cpy konstruktorn" << endl;
  CellphoneHandler anotherCPHandler(aCPHandler);
  cout << "9.(nytt objekt) \n"  << anotherCPHandler.getPhonesToString();//9

  return 0;
}
