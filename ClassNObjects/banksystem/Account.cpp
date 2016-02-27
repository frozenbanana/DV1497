#include "Customer.h"
#include <iostream>
#include <sstream>
Account::Account(int accountNumber){
  this->accountNumber = accountNumber;
}

Account::~Account(){};
Account::int getAccountNumber(){
  return this->accountNumber;
}
Account::void setAccountNumber(int accountNumber){
  this->accountNumber = accountNumber;
}
Account::virtual void toStringSpecific()const = 0;

Account:: void toString()const{
  cout << "Account Number: " << getAccountNumber() << endl;
  return toStringSpecific();
}
