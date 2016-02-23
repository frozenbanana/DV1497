#ifndef Employee_h_
#define Employee_h_
#include "Person.h"

using namespace std;

class Employee : public Person {
		private: 
		string department;
		int salary;
public:
	Employee(const Employee &orig) :Person(orig){
		this->department = orig.department;
		this->salary = orig.salary;
	}
	Employee& operator =(const Employee &orig){
		if (this != &orig){
			Person::operator=(orig);
			this->department = orig.department;
		}
		return *this;
	}
	Employee(string name, string email, string department, int salary) : Person(name, email){
		this->department = department;
		this->salary = salary;
	}
	~Employee(){}
	virtual string toStringSpecific() const{
		stringstream ss;
		ss << this->department << this->salary;
		return ss;
	}
	string toString(){
		cout << this->getName << this->getEmail;
		return toStringSpecific();
	}
	void setDepartment(string department){
		this->department = department;
	}
	void setSalary(int salary){
		this->salary = salary;
	}
	string getDepartment(){
		return this->department;
	}
	int getSalary(){
		return this->salary;
	}

	/*¨Glöm int att klassen som ärver ska i sin konstruktor ":förälder(parametrar)"*/

};
#endif
