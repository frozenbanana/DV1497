#include "Account.h"
#include "SavingsAccount.h"
#include <iostream>
#include <sstream>
using namespace std;

SavingsAccount::SavingsAccount(double savingRate, double balance){
    this->savingsRate = savingRate;
    this->balance = balance;
}
SavingsAccount::~SavingsAccount(){}
SavingsAccount::double getSavingRate(){
  return this->savingRate;
}
SavingsAccount::void setSavingRate(double savingRate){
    this->savingRate = savingRate;
}
SavingsAccount::double getBalance(){
  return this->balcance;
}
SavingsAccount::void setBalance(double balance){
  this->balance = balance;
}
SavingsAccount::double getFinalBalance(){
  return this->balance * this->savingRate;
}
SavingsAccount::string toStringSpecific(){
    stringstream ss;
    ss << "Saving rate: " << getSavingRate() << "\n Balance: " << getBalance()
      << "Final balance: " << getFinalBalance() << endl;
    return ss;
}
