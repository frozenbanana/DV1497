#ifndef Person_h_
#define Person_h_
#include <iostream>
#include <sstream>
#include <string>


using namespace std;

class Person{
	private:
		string name;
		string email;
	public:
		Person(const Person &orig){
			this->name = orig.name;
			this->email = orig.email;
		}
		Person& operator =(const Person &orig){
			if (this != &orig){
				this->name = orig.name;
				this->email = orig.email;
			}
			return *this;
		}
		virtual ~Person(){};
		string getName() const{
			return this->name;
		}
		string getEmail() const{
			return this->email;
		}
		void setName(string name){
			this->name = name;
		}
		void setEmail(string email){
			this->email = email;
		}
		Person(string name, string email){
				this->name = name;
				this->email = email;
	    }
		virtual string toStringSpecific() const = 0;
		string toString(){
			cout << this->getName() << this->getEmail();
			return toStringSpecific();
		}


	/*¨Glöm int att klassen som ärver ska i sin konstruktor ":förälder(parametrar)"*/
	
};
#endif
