#ifndef Friend_H
#define Friend_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
class Friend
{
public:
	Friend();
	Friend(string name, string dateOfBirth, string adress, string email, string phoneNumber);
	~Friend();

	string getName()const;
	string getDateOfBirth()const;
	string getAdress()const;
	string getEmail()const;
	string getPhoneNumber()const;

	void setName(string name);
	void setDateOfBirth(string dateOfBirth);
	void setAdress(string adress);
	void setEmail(string email);
	void setPhoneNumber(string phoneNumber);

	bool operator ==(const Friend & otherFriend) const;
	bool operator <(const Friend & otherFriend) const;

	string toString() const;
private:
	string name;
	string dateOfBirth;
	string adress;
	string email;
	string phoneNumber;
};


#endif
