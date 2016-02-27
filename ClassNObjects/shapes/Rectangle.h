#ifndef Rectangle_h
#define Rectangle_h
#include "Shape.h"
#include <sstream>
//Rectangle.h
class Rectangle : public Shape
{
  private:
    int width, length;
    public:
  Rectangle(int x, int y, int width, int length) : Shape(x,y) {
    this->length=length;
    this->width=width;
  }
  ~Rectangle(){}
  //set get
  int getArea()const{
    return this->width * this->length;
  }
  int getPerimeter()const{
    return 2*(this->length + this->width);
  }
  string toStringSpecfic()const{
    stringstream ss;
    ss << "Rectangle " << this->getArea() << "," << this->getPerimeter() << endl;
    return ss.str();
  }


};
#endif
