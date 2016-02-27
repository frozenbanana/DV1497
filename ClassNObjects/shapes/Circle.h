//Circle.h
#ifndef Circle_h
#define Circle_h

#include "Shape.h"
#define PI 3.14159226
class Circle : public Shape
{
  private:
    double radius;
  public:
  Circle(int x, int y, double radius) : Shape(x,y){
    this->radius=radius;
  }
  ~Circle(){}
  //set get
  double getArea()const {
    return PI*this->radius * this->radius;
  }
  double getPerimeter()const {
    return (2*PI * this -> radius);
  }
  string toStringSpecific() const{
    stringsteam ss;
    ss << "Circle" << getArea() << getPerimeter() << endl;
    return ss;
  }
};
#endif
