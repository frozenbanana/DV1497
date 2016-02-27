#ifndef CELLPHONE_H
#define CELLPHONE_H
#include <string>
using namespace std;
class Cellphone
{
  private:
    string modelName;
    int stock;
    int price;

  public:
    Cellphone();
    Cellphone(string modelName, int stock, int price);
    ~Cellphone();
    Cellphone& operator =(const Cellphone& orig);
    void setModelName(string modelName);
    void setStock(int stock);
    void setPrice(int price);
    string getModelName() const;
    int getStock() const;
    int getPrice() const;
    string toString() const;
};
#endif
