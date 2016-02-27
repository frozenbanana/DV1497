#ifndef SavingsAccount_h
#define SavingsAccount_h
#include <iostream>
class SavingsAccount: public Account{
  private:
    double savingsRate;
    double balance;
  public:
    SavingsAccount(double SavingRate, double balance);
    ~SavingsAccount();
    double getSavingRate();
    void setSavingRate();
    double getBalance();
    void setBalance();
    double getFinalBalance();
    string toStringSpecific();
}
#endif
