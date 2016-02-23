#ifndef UNIVERSITY_REG_H
#define UNIVERSITY_REG_H

#include "Student.h"
#include "Employee.h"

class UniversityReg {
private:
	Person** persons;
	int nr_of_persons;
	int capacity;

	void expand();
	void freeMemory();

public:
	UniversityReg();
	UniversityReg(int capacity);
	UniversityReg(const UniversityReg &original);
	virtual ~UniversityReg();
	void add(string name, string mail, int reg_nr);						// Student
	void add(string name, string mail, string department, int salary);	// Employee

	int getNumberOfStudents() const;
	int getNumberOfEmployees() const;


};

#endif