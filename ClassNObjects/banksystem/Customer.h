#ifndef Costumer_h
#define Costumer_h
#include "Account.h"

class Costumer{
  private:
    string name;
    Account *accs;//max 20
  public:
    Costumer(string name, &accs);
    ~Costumer();
    string getName()const;
    void setName();
    void toString();
}
#endif
