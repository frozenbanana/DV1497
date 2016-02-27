//Shape.h
#ifndef Shape_H
#define Shape_H
#include <iostream>
using namespace std;
class Shape{
  private:
    int x;
    int y;
  public:
    Shape(int x, int y){
      this->x = x;
      this->y = y;
    }
    virtual ~Shape(){}
    virtual string toStringSpecific()const=0; // om du inte overloadar så är det = 0
    string toString()const{ // virtual betyder = ALLA MINA BARN MÅSTE HA DETTA
      cout << "Coordinates are: "
      << this->x <<"," <<this->y << endl;
      return toStringSpecific();
    }

};
#endif
