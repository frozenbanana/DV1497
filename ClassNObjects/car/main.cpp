#include "CarContainer.h"
using namespace std;

int main(){
  string arr[10];
/*  CarContainer carContainer_1;
  carContainer_1.addCar("volvo", 2012);
  carContainer_1.addCar("BMW", 2010);
  carContainer_1.addCar("SAAB", 2008);
  carContainer_1.addCar("Ferrari", 2005);

  CarContainer carContainer_2 = carContainer_1;// shallow cpying
  carContainer_1.getCarAsString(arr, carContainer_1.getNrOfCars());
    cout << "carContainer_1\n";
  for(int i = 0; i <carContainer_1.getNrOfCars(); i++){
    cout << arr[i] << endl;
  }
  carContainer_2.getCarAsString(arr, carContainer_2.getNrOfCars());
    cout << "carContainer_2\n";
  for(int i = 0; i <carContainer_2.getNrOfCars(); i++){
    cout << arr[i] << endl;
  }
  carContainer_1.removeCar("volvo",2012);
  */
  CarContainer carContainer_1;
    carContainer_1.addCar("volvo", 2012);
    carContainer_1.addCar("bögbil", 2009);
    carContainer_1.addCar("fiskbil", 2008);
    carContainer_1.addCar("bajsbil", 2006);
  CarContainer carContainer_2;
    carContainer_2.addCar("volvo2", 2012);
    carContainer_2.addCar("fiskbil2", 2008);
    carContainer_2.addCar("bajsbil2", 2006);
    carContainer_2.addCar("bögbil2", 2009);
  carContainer_1.getCarAsString(arr, carContainer_1.getNrOfCars());
  for(int i = 0; i <carContainer_1.getNrOfCars(); i++){
    cout << arr[i] << endl;
  }
  carContainer_2.getCarAsString(arr, carContainer_2.getNrOfCars());
  for(int i = 0; i <carContainer_2.getNrOfCars(); i++){
    cout << arr[i] << endl;
  }
  return 0;
}

