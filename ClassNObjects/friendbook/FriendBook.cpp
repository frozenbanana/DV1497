#include "FriendBook.h"

FriendBook::FriendBook(){
	this->nrOfFriends = 0;

	for (int i = 0; i < SIZE ; i++)
	{
		this->friends[i] = NULL;
	}
  }
FriendBook::~FriendBook(){

	for (int i = 0; i < SIZE; i++) {
    delete this->friends[i];
	}
}
void FriendBook::FriendBookFour(){
  this->capacity = 20;
  this->nrOfFriends = 0;
  this->friends4 = new *friends[capacity];
  for (int i = 0; i < capacity; i++) {
    this->friends4[i] = NULL;
  }
}

void FriendBook::FriendBookFourDe(){
  for (int i = 0; i < nrOfFriends; i++) {
    delete friends[i];
 }
  delete [] friends;
}
void FriendBook::setName(string name){
  this->name = name;
}
bool FriendBook::addFriend(string name, string dateOfBirth, string adress, string email, string phoneNumber){
	friends[this->nrOfFriends] = new Friend(name, dateOfBirth, adress, email, phoneNumber);
	if (existFriend()){
		cout << "not successfull!";
		return false;
	}
	else{
		nrOfFriends++;
  }
	return true;
}

bool FriendBook::existFriend() const{
	bool exist = false;
	for (int i = 0; i < nrOfFriends; i++)
	{
		if (this->friends[nrOfFriends] == this->friends[i])
		{
			cout << "This Friend already exist!\n";
			exist = true;
		}
  }
		return exist;
}

void FriendBook::printAll() const{
		if (this->nrOfFriends == 0)
			cout << "No friends in friendbook!\n";
		else{
			for (int i = 0; i < nrOfFriends; i++)
			{
				cout << this->friends[i]->toString();
			}
		}
	}
void FriendBook::saveAll() const{
  ofstream myfile;
  string filename;
  filename = this->name +".txt";
  myfile.open (filename.c_str());
  if(myfile.is_open()){
    myfile << nrOfFriends << endl;
    for(int i = 0; i < nrOfFriends;i++){
      myfile << this->friends[i]->getName() << endl;
      myfile << this->friends[i]->getAdress() << endl;
      myfile << this->friends[i]->getDateOfBirth() << endl;
      myfile << this->friends[i]->getEmail() << endl;
      myfile << this->friends[i]->getPhoneNumber() << endl;
      myfile << endl;
      }
    }
    else
      cout << "File could not be opened!\n";
    myfile.close();
}
