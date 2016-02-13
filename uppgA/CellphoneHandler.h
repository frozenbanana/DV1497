#ifndef CELLPHONEHANDLER_H
#define CELLPHONEHANDLER_H
#include "Cellphone.h"
#include <string>
using namespace std;
class CellphoneHandler
{
  private:
    string name;
    int amountPhones;
    Cellphone **cellphones;
    int capacity;
  public:
    CellphoneHandler();
    CellphoneHandler(string name, int capacity);
    ~CellphoneHandler();
    CellphoneHandler(CellphoneHandler const& orig); // cpy konstruktor
    void setHandlerName(string name);
    string getHandlerName();
    void addPhone(string name, int stock, int price);
    bool removePhone(string name);
    void changePrice(int priceLimit, double discount);
    void expand();
    int exists(string name);
    bool writeToFile(string fileName);   //Spara alla mobiltelefoner på fil där filnamnet matas in av användaren
    bool readFromFile(string fileName);  //Läsa alla mobiltelefoner från fil där filnamnet matas in av användaren
    string getPhonesToString();

};
#endif
