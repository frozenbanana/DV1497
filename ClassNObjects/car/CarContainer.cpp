#include "CarContainer.h"
CarContainer& CarContainer::operator =(const CarContainer &orig){
    if(this != &orig){
      this->nrOfCars = orig.nrOfCars;
      for(int i = 0; i < nrOfCars; i++){
          delete cars[i];
      }
      delete[] this->cars;               // kan skrivas som en funktion freeMemory()
      this->cars = new Car*[5];
      for (int i = 0; i < this->nrOfCars; i++) { // kan skrivas som en funktio makeCopy()
       this->cars[i] = new Car(*orig.cars[i]);
     }
    }
    return *this;
}
CarContainer::CarContainer(const CarContainer &orig){ // det räcker att skicka in orginalet som reference för att kopiera
  this->nrOfCars = orig.nrOfCars;                     // detta är en copy funktion som har deep cpy
  this->cars = new Car*[5];
  for(int i = 0; i < nrOfCars; i++){             // detta fixar deep cpy
    cars[i] = new Car(*orig.cars[i]);
  }
}
bool CarContainer::addCar(string make, int yearModel){
  bool flag = false;
  if (this->nrOfCars < 5){
    this->cars[nrOfCars++] = new Car(make,yearModel);
    flag = true;
  }
  return flag;
 }
bool CarContainer::removeCar(string make, int yearModel){
  bool flag = false;
  for(int i = 0; i <this-> nrOfCars; i++){
    if (this->cars[i]->getMake() == make && cars[i]->getYearModel() == yearModel){
        this->cars[i]->setMake(this->cars[i+1]->getMake());
        this->cars[i]->setYearModel(this->cars[i+1]->getYearModel());
      }
  }
}
void CarContainer::getCarAsString(string (&arr)[10], int nrOfCars){
    for(int i = 0; i < this->nrOfCars; i++){
      arr[i] = cars[i]->toString();
    }
}
