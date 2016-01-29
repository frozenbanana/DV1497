#include "Friend.h"


Friend::Friend(){
	this->name = "unknown";
	this->dateOfBirth = "unknown";
	this->adress = "unknown";
	this->email = "unknown";
	this->phoneNumber = "unknown";
}
Friend::Friend(string name, string dateOfBirth, string adress, string email, string phoneNumber){
	this->name = name;
	this->dateOfBirth = dateOfBirth;
	this->adress = adress;
	this->email = email;
	this->phoneNumber = phoneNumber;
}
Friend::~Friend()
{

}

string Friend::getName()const{
	return this->name;
}
string Friend::getDateOfBirth()const{
	return this->dateOfBirth;
}
string Friend::getAdress()const{
	return this->adress;
}
string Friend::getEmail()const{
	return this->email;
}
string Friend::getPhoneNumber()const{
	return this->phoneNumber;
}

void Friend::setName(string name){
	this->name = name;
}
void Friend::setDateOfBirth(string dateOfBirth){
	this->dateOfBirth = dateOfBirth;
}
void Friend::setAdress(string adress){
	this->adress = adress;
}
void Friend::setEmail(string email){
	this->email = email;
}
void Friend::setPhoneNumber(string phoneNumber){
	this->phoneNumber = phoneNumber;
}

bool Friend::operator ==(const Friend & otherFriend) const{
	return this->name == otherFriend.name && this->dateOfBirth == otherFriend.dateOfBirth && this->adress == otherFriend.adress && this->email == otherFriend.email && this->phoneNumber == otherFriend.phoneNumber;
}
bool Friend::operator <(const Friend & otherFriend) const{
	return this->dateOfBirth < otherFriend.dateOfBirth;
}

string Friend::toString() const{
	stringstream ss;
	ss << "Friend: " << this->name << " ,Date of birth: " << this->dateOfBirth << " ,E-mail: " << this->email << " ,Phone Number: " << this->phoneNumber << endl;
		return ss.str();
}

