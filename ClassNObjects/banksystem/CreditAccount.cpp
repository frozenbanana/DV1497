#include "Account.h"
#include <iostream>
#include <sstream>
using namespace std;

CreditAccount::CreditAccount(double balance, double creditLimit, double debtInterest){
    this->balance = balance;
    this->creditLimit = creditLimit;
    this-> debtInterest = debtInterest;
}
CreditAccount::~CreditAccout(){}
CreditAccount::void setBalance(double balance){
  this-balance = balance;
}
CreditAccount::void setCreditLimit(double creditLimit){
  this->creditLimit = creditLimit;
}
CreditAccount::void setDebtInterest(double debtInterest){
  this->debtInterest = debtInterest;
}
CreditAccount::double getBalance(){
  return this->balance;
}
CreditAccount::double getCreditLimit(){
  return this->creditLimit;
}
CreditAccount::double getDebtInterest(){
  return this->debtInterest;
}
CreditAccount::double getFinalBalance(){
  // Är kontot ett 
  // kreditkonto ska eventuell skuld beräknas som saldot multiplicerat med 
  // skuldräntan
  double finalBalance;
  if(creditLimit < 0){
    finalBalance = this->balance * this->debtInterest;
  }
  return finalBalance;
}
CreditAccount::string toStringSpecific(){
  stringstream ss;
  ss << "Balance: " << getBalance() << "\nCredit Limit: " << getCreditLimit()
    << "\nDebt limit: " << getDebtInterest() << "\nFinal Balance: " << getFinalBalance() << endl;
  return ss.str();
}
