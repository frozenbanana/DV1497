#include "Circle.h"
#include "Rectangle.h"
#include <iostream>
using namespace std;

int main()
{
/*  Shape *sh = new Circle(10,20,3.0);
 cout <<  sh->toString();

  Circle *c = new Circle(10,20,3.0);
  cout << c->toString();
*/
  Shape *shapes[4];
  shapes[0] = new Circle(1,2,3.0);
  shapes[1] = new Circle(4,5,6.0);
  shapes[2] = new Rectangle(7,8,9,10);
  shapes[3] = new Rectangle(11,12,13,14);

  for(int i= 0; i < 4; i++){
    cout << shapes[i] -> toString() << endl;
  }

  Circle *circlePtr = NULL;

  for(int i = 0; i < 4; i++){
    circlePtr = dynamic_cast<Circle*>(shapes[i]);
    if( circlePtr != NULL){
      cout << "This is a circle! Index: " << i << endl;
    }
  }
  return 0;
}
