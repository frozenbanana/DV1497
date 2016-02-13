#ifndef Account_h
#define Account_h
class Account{
  private:
    int accountNumber;
  public:
    AccountNumber(int accountNumber); // inte säker
    ~AccountNumber();
    int getAccountNumber();
    void setAccountNumber();
    virtual void toString()const = 0;
};
#endif
