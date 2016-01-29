#include "Employee.h"

using namespace std;

Employee::Employee(){
  this->name = "Unknown";
  this->employeeNr = 0;
  this->dateOfBirth = 0;
  this->salary = 0;
  this->employeeStart = 0;
  this->EmployeeTime = 0;
}
Employee::Employee(string name, int employeeNr, int dateOfBirth, int salary, int employeeStart){
  time_t now = time(0);

  this->name = name;
  this->employeeNr = employeeNr;
  this->dateOfBirth = dateOfBirth;
  this->salary = salary;
  this->employeeStart = employeeStart;
  this->employeeTime = now - employeeStart;
}
Employee::~Employee(){
   delete(this);
}

String Employee::getName() const{
  return this->name;
}
int Employee::getEmployeeNr() const{
  return this->employeeNr;
}
int Employee::getDateOfBirth() const{
  return this->dateOfBirth;
}
int Employee::getSalary() const{
  return this->salary;
}
int Employee::getEmployeeStart() const{
  return this->employeeStart;
}
int Employee::getEmployeeTime() const{
  return this->employeeTime;
}

void Employee::getName(string name) const{
  this->name = name;
}
void Employee::getEmployeeNr(int employeeNr ) const{
  this->employeeNr = employeeNr;
}
void Employee::getDateOfBirth(int dateOfbirth) const{
  this->dateOfBirth = dateOfBirth;
}
void  Employee::getSalary(int salary) const{
  this->salary = salary;
}
void Employee::getEmployeeStart(int employeeStart) const{
  this->employeeStart = employeeStart;
}
void Employee::getEmployeeTime(int now) const{
  this->employeeTime = now - this->employeeStart;
}

string Employee::toString() const{
   stringstream ss;
   ss << "Employee name: "
     << this->name
     << " ,Employee Number: "
     << this->employeeNr
     << " ,Date of birth: "
     << this->dateOfBirth
     << " ,Salary: "
     << this->salary
     << " ,Employee since: "
     << this->employeeStart
     << " ,Total time employeed: "
     << this->employeeTime
     << endl;
  return ss.str();
}
