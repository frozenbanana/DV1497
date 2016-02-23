#ifndef UniversityReg_h_
#define UniversityReg_h_
#include "Person.h"


class UniversityReg{
private: 
	int nrOfPersons;
	Person **persons;
	int capacity;
public:
	bool addStudent(string name, string email, int regNr);
	bool addEmployee(string name, string email, int salary, string department);
	bool removeStudent(string name, string email, int regNr);
	bool removeEmployee(string name, string email, int salary, string department);
	UniversityReg& operator=(const UniversityReg &orig);

	UniversityReg(int capacity);
	UniversityReg(const UniversityReg &orig);
	UniversityReg();
	~UniversityReg();
	int getNrOfPersons();
	int getNrOfEmployees();
	int getNrOfStudents();
	void printAllPersons() const;
};
#endif