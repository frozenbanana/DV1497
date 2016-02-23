#include <typeinfo>
#include <string>
#include <iostream>
#include <sstream>
#include "Student.h"
#include "Employee.h"
#include "UniversityReg.h"


using namespace std;
bool UniversityReg::addStudent(string name, string email, int regNr){
	bool flag = false;
	if (this->nrOfPersons < this->capacity){
		this->getNrOfPersons[this->nrOfPersons] = new Student(name, email, regNr);
		flag = true;
	}
	return flag;
}
bool UniversityReg::addEmployee(string name, string email, int salary, string department){
	bool flag = false;
	if (this->nrOfPersons < this->capacity){
		this->getNrOfPersons[this->nrOfPersons] = new Employee(name, email, department);
		flag = true;
	}
	return flag;
}

bool UniversityReg::removeStudent(string name, string email, int regNr){
	bool flag = false;
	Student* studentptr = nullptr;
	for (int i = 0; i < this->nrOfPersons; i++){
		studentptr = dynamic_cast<Student*>(persons[i]);
		if (studentptr != nullptr && this->getNrOfPersons[i]->getName() == name && this->persons[i]->getEmail() == email && this->persons[i]->getRegNr() == regNr){
			delete persons[i];
			persons[i] = persons[--nrOfPersons];
			flag = true;
		}
	}
	return flag;
}
bool UniversityReg::removeEmployee(string name, string email, int salary, string department){
	bool flag = false;
	Employee* employeeptr = nullptr;
	for (int i = 0; i < this->nrOfPersons; i++){
		employeeptr = dynamic_cast<Employee*>(persons[i]);
		if (employeeptr != nullptr && this->getNrOfPersons[i]->getName() == name && this->persons[i]->getEmail() == email &&
			this->persons[i]->getSalary == salary&& this->getNrOfPersons[i]->getDepartment == department){
			delete persons[i];
			persons[i] = persons[--nrOfPersons];
			flag = true;
		}
	}
	return flag;
}
UniversityReg& UniversityReg::operator=(const UniversityReg &orig){
	if (this != &orig){
		for (int i = 0; i < this->nrOfPersons; i++){
			delete this->nrOfPersons[i];
		}
		delete this->nrOfPersons;
		this->nrOfPersons = orig.nrOfPersons;
		this->capacity = orig.capacity;
		this->persons = new Person*[this->capacity];
	}
	for (int i = 0; i < this->nrOfPersons; i++)
	{
		if (typeid(*orig.nrOfPersons[i]))
	}
}
UniversityReg::UniversityReg(int capacity){
	this->getNrOfPersons = 0;
	this->capacity = capacity;
	this->persons = new Person*[this->capacity];
}
UniversityReg::UniversityReg();
UniversityReg::~UniversityReg(){
	for (int i = 0; i < this - nrOfPersons; i++){
		delete this->nrOfPersons[i];
	}
	delete[] this->persons;
}
int UniversityReg::getNrOfPersons();
int UniversityReg::getNrOfEmployees(){
	int nrOfEmployees = 0;
	Student* employeeptr = nullptr;
	for (int i = 0; i < this->nrOfPersons; i++){
		employeeptr = dynamic_cast<Employee*>(persons[i]);
		if (employeeptr != nullptr){
			nrOfEmployees++;
		}
	}
	return nrOfEmployees;
}
int UniversityReg::getNrOfStudents(){
	int nrOfStudents = 0;
	Student* studentptr = nullptr;
	for (int i = 0; i < this->nrOfPersons; i++){
		studentptr = dynamic_cast<Student*>(persons[i]);
		if (studentptr != nullptr){
			nrOfStudents++;
		}
	}
	return nrOfStudents;
}
void UniversityReg::printAllPersons() const{
	for (int i = 0; i < this->nrOfPersons; i++){
		this->getNrOfPersons[i]->toString();
	}
	UniversityReg::UniversityReg(const UniversityReg &orig){
		this->nrOfPersons = orig.nrOfPersons;
		this->capacity = orig.capacity;
		this->persons = new Person*[this->capacity];
		for (int i = 0; i < this->nrOfPersons; i++){
			if (typeid(*orig.persons[i]) == typeid(*student) orig.persons[i]){
				this->persons[i] = new Employee(*((*Employee)orig.persons[i]));
			}
			else{
				this->persons[i] = new Student(*((*Student)orig.persons[i]));
			}
		}
		return *this;
	}
}
