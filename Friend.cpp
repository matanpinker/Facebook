#include <iostream>
using namespace std;

#include "Friend.h"

Friend::Friend(const char* theName, const Date& BirthDate) : Account(theName), birthDate(BirthDate)
{	
	id = counter++;
}
int Friend::counter = 1000;

ostream& operator<<(ostream& os, const Friend& theFriend)
{
	os << "Friend's name: " << theFriend.name << "\n";
	os << "Birth Date: ";
	os << theFriend.birthDate << "\n"; //Using the << operator of Date
	os << "ID: " << theFriend.id << "\n";
	if (theFriend.myFriends.size() == 0)
	{
		os << "This friend is all alone :(\n";
	}
	else
	{
		os << "The linked friends:\n";
		for (const auto& friend1 : theFriend.myFriends)
		{
			os << friend1->getName() << " (ID:" << friend1->id << ")" << "\n";
		}
	}

	if (theFriend.myFanPages.size() == 0)
	{
		os << "This friend is not a fan of any fan page.\n";
	}
	else
	{
		os << "The linked fanpages:\n";
		for (const auto& fanpage : theFriend.myFanPages)
		{
			os << fanpage->getName() << " (ID:" << fanpage->getFanPageID() << ")" << "\n";
		}
	}
	return os;
}

int Friend::getFriendID() const
{
	return id;
}


void Friend::showStatuses() const //we need to add passing at Account::showStatuses 
{
	cout << "This friend has " << myStatuses.size() << " statuses";
	Account::showStatuses();
}

int Friend::getNumOfFanPages() const
{
	return myFanPages.size();
}

bool Friend::fanPageExist(const FanPage* fp) const
{
	for (const auto& fanPage : myFanPages)
	{
		if (fp == fanPage)
			return true;
	}
	return false;
}

void Friend::linkFanPage(FanPage* theFanPage)
{
	myFanPages.push_back(theFanPage);
}

void Friend::unLinkFanPage(FanPage* theFanPage)
{
	myFanPages.erase(std::remove(myFanPages.begin(), myFanPages.end(), theFanPage), myFanPages.end());
}


bool Friend::friendExist(const Friend* theFriend) const
{
	for (const auto friend1 : myFriends)
	{
		if (theFriend == friend1)
			return true;
	}
	return false;
}

char* Friend::getName() const
{
	return name;
}

bool Friend::operator<(const Friend& other) const
{
	return myStatuses.size() < other.myStatuses.size();
}