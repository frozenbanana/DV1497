#ifndef CARCONTAINER_H
#define CARCONTAINER_H
#include "Car.h"

class CarContainer{
  private:
    Car **cars = new Car*[5];
    int nrOfCars;

  public:
    CarContainer(){
      this->nrOfCars = 0;
    }

    CarContainer& operator=(const CarContainer &orig); // assignemtn operator overload

    CarContainer(const CarContainer &orig);

    ~CarContainer(){
      for(int i; i < this->nrOfCars; i++){
        delete cars[i];
      }
      delete [] cars;
    }
    int getNrOfCars()const{
      return this->nrOfCars;
    }
    bool addCar(string make, int yearModel);
    void getCarAsString(string (&arr)[10], int nrOfCars);
    bool removeCar(string make, int yearModel);
};

#endif
