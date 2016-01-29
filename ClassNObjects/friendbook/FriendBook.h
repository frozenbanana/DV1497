#ifndef FriendBook_H
#define FriendBook_H

#include "Friend.h"

#define SIZE 100
class FriendBook
{
public:
	FriendBook();
	~FriendBook();

	FriendBookFour();
	~FriendBookFour();
	bool addFriend(string name, string dateOfBirth, string adress, string email, string phoneNumber);
  void setName(string name);
	bool existFriend() const;
	void printAll() const;
  void saveAll() const;
private:
	int nrOfFriends;
	Friend *friends[SIZE];
  Friend **friends4;
  int capacity;
	string name;
	int year;
};

#endif
