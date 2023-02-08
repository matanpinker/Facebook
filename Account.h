#ifndef __ACCOUNT_H
#define __ACCOUNT_H

#pragma warning(disable: 4996)
#include "Status.h"
#include "DateAndTime.h"
#include <vector>

class FanPage;
class Friend;

class Account
{
protected:
	char* name;

public:
	std::vector<Friend*> myFriends;
	std::vector<Status*> myStatuses;

	Account(const char* theName);
	~Account();
	const char* getName() const;

	virtual void showStatuses() const;
	void showMyFriends() const;
	void addStatus(Status* TheStatus);

	void linkFriend(Friend* TheFriend); //cannot be const because we change booth friends
	void unLinkFriend(Friend* TheFriend); //cannot be const because we change booth friends

	int getNumOfFriends() const;
	int getNumOfStatuses() const;

	Friend* getFriendByIndex(int i) const;
	Status* getStatusByIndex(int i) const;

};

#endif //__ACCOUNT_H