#include "person.h"

int main(){
  Person p1("Eva", 23);
  p1.introduce();
  Person p2 = p1;
  p2.introduce();

  p1.changeNameAndAge("sara",80);
  p1.introduce();
  p2.introduce();

  return 0;
}
