#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Car{
  private:
    string make;
    int yearModel;
  public:
    Car(){
        this->make = "unkown";
        this->yearModel = 0;
    }
    string toString()const{
      stringstream ss;
      ss << this->make<< ", " <<this->yearModel << endl;
      return ss.str();
    }
    Car(string make, int yearModel){
      this->make = make;
      this->yearModel = yearModel;
    }
    ~Car(){};
    int getYearModel() const{
      return this->yearModel;
    }
    void setYearModel(int yearModel){
      this->yearModel = yearModel;
    }
    string getMake() const{
      return this->make;
    }
    void setMake(string make){
      this->make = make;
    }
};

#endif
