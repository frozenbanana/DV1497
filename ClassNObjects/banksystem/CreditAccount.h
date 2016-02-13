#ifndef CreditAccount_h
#define CreditAccount_h
#include "Account.h"
#include <iostream>

class CreditAccount: public Account{
    private:
      double balance;
      double creditLimit;
      double debtInterest;
   public:
      CreditAccount(double balance, double creditLimit, double debtInterest);
      ~CreditAccout();
      void setBalance();
      void setCreditLimit();
      void setDebtInterest();
      double getBalance();
      double getCreditLimit();
      double getDebtInterest();

      double getFinalBalance();
      string toStringSpecific();
}
#endif
