#ifndef Student_h_
#define Student_h_

#include "Person.h"

using namespace std;
class Student: public Person{
private:
	int regNr;
public:
	Student(const Student &orig) :Person(orig){
		this->regNr = origNr;
	}
	Student(string name, string email, int regNr) : Person(name, email){
		this->regNr = regNr;
	}
	Student& operator =(const Student &orig){
		if (this != orig){
			Person::operator=(orig);
			this->regNr = orig.regNr;
		}
		return *this;
	}
	~Student(){}
	virtual string toStringSpecific() const{
		stringstream ss;
		ss << this->regNr;
		return ss;
	}
	void setRegNr(int regNr){
		this->regNr = regNr;
	}

	int getRegNr(){
		return this->regNr;
	}
#endif
