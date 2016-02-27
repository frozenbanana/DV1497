#include "UniversityReg.h"
#include <iostream>
#include <sstream>
#include <string>

int main(){
	/*
	//test cpy construktor
	Person* p1 = new Student("name1", "email", 123);
		Person* p2 = p1;
	p1->toString;
	p2->toString;
	//test deep copying
	p1->setName("BOB");
	cout << p1->toString();
	cout << p2->toString();
	*/

	UniversityReg bth;
	bth.addPerson("name1", "name1@bth.se", 123);
	bth.addEmployee("name2", "name2@bth.se", 2000, "IT");
	bth.printAllPersons;
	UniversityReg kth;
	kth.addStudent("name3", "name3@kth.se", 456);
	kth = bth;
	kth.printAllPersons();
	return 0;
}