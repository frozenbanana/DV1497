#include "WoodHandler.h"
#include "Panel.h"
#include "Joist.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
  // test av konstruktor
	WoodHandler testhandler;
	testhandler.addPanel("10x20",20,"profile1", true);
	testhandler.addPanel("10x25",25,"profile2", false);
	testhandler.addPanel("10x35",35,"profile3", false);
  cout << "From constructor: " << endl;
	cout << testhandler.printAllWood() << endl;
	// test av tilldelningsoperator
	WoodHandler testhandler2;
	testhandler2 = testhandler;
    cout << "From assignment operator constructor: "<< endl;
	cout << testhandler2.printAllWood() << endl;
  // test av cpy konstrukor
  WoodHandler testhandler3(testhandler);
	cout << "From cpy constructor: " << endl;
	cout << testhandler3.printAllWood() << endl;

  return 0;
}
