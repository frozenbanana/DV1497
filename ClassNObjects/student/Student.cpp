#include "Student.h"


  Student::Student(string name, string program, int phoneNumber, int dateOfBirth){
      this->name = name;
      this->program = program;
      this->phoneNumber = phoneNumber;
      this->dateOfBirth = dateOfBirth;
  }
  Student::~Student(){

  }
  void Student::setDateOfBirth(int dateOfBirth){
      //day max 31 - month max 12
      int day;
      int month;
      int temp;

      temp = dateOfBirth % 10000; // om 20160126 -> temp = 0126
      day = temp % 100;
      month = temp / 100;

  }
  void Student::setName(string name){
    this->name = name;
  }
  string Student::getName()const{
    return this->name;
  }
  void Student::setProgram(string program){
    this->program = program;
  }
  string Student::getProgram()const{
    return this->program;
  }
  void Student::setPhoneNumber(int phoneNumber){
    this->phoneNumber = phoneNumber;
  }
  int Student::getPhoneNumber()const{
    return this->phoneNumber;
  }
  int Student::getDateOfBirth()const{
   return this->dateOfBirth;
  }

  void Student::show(){
    cout << "Name: "
      << this->name
      << "\nProgram:"
      << this->program
      << "\nPhone number: "
      << this->phoneNumber
      << "\nDate of birth: "
      << this->dateOfBirth
      << endl;
  }
