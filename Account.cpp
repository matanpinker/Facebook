#include <iostream>
using namespace std;

#include "Account.h"

Account::Account(const char* theName)
{
	name = new char[strlen(theName) + 1];
	strcpy(name, theName);

	myFriends = vector<Friend*>();
	myStatuses = vector<Status*>();
}

Account::~Account()
{
	delete[] name;
}

const char* Account::getName() const
{
	return name;
}


void Account::showStatuses() const
{
	if (myStatuses.size() == 0) // if the account dosent have status end here
	{
		cout << ".\n";
	}
	else // if the account have status show them all
	{
		cout << ":\n";
	}
	int i = 0;
	for (const auto &status : myStatuses)
	{
		cout << "Status #" << i + 1 << ":\n";
		cout << *status; //Using the << operator
		i++;
	}
}

void Account::addStatus(Status* theStatus)
{
	myStatuses.push_back(theStatus);
}

void Account::linkFriend(Friend* theFriend)
{
	myFriends.push_back(theFriend);
}

void Account::unLinkFriend(Friend* theFriend)
{
	myFriends.erase(std::remove(myFriends.begin(), myFriends.end(), theFriend), myFriends.end());
}

int Account::getNumOfFriends() const
{
	return myFriends.size();
}

int Account::getNumOfStatuses() const
{
	return myStatuses.size();
}

void Account::showMyFriends() const
{

}

Friend* Account::getFriendByIndex(int i) const
{
	if (i < 0 || i >= myFriends.size())
	{
		return nullptr;
	}
	return myFriends[i];
}

Status* Account::getStatusByIndex(int i) const
{
	if (i < 0 || i >= myStatuses.size())
	{
		return nullptr;
	}
	return myStatuses[i];
}