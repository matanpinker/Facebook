#include <iostream>
using namespace std;

#include "FanPage.h"

//    FANPAGE CTOR
FanPage::FanPage(const char* theName) : Account(theName)
{
	id = counter++;
}
int FanPage::counter = 2000;

//FANPAGE DTOR
FanPage::~FanPage()
{

}

char* FanPage::getFanPageName() const
{
	return name;
}

int FanPage::getFanPageID() const
{
	return id;
}


ostream& operator<<(ostream& os, const FanPage& theFanPage)
{
	os << "FanPage's name: " << theFanPage.name << "\n";
	os << "ID: " << theFanPage.id << "\n";
	//it is a problem, maybe because the include. need to check it
	if (theFanPage.myFriends.empty())
	{
		os << "This fanpage has no fans.\n";
	}
	else
	{
		os << "The fans of this page:\n";
		for (int i = 0; i < theFanPage.getNumOfFriends(); i++) 
		{
			os << theFanPage.getFriendByIndex(i)->getName() << " (ID: " << theFanPage.getFriendByIndex(i)->getFriendID() <<")\n";
		}
	}
	return os; 
}

void FanPage::showStatuses() const
{
	cout << "This fanpage has " << myStatuses.size() << " statuses";
	Account::showStatuses();
}

bool FanPage::operator==(const FanPage& other) const
{
	return (this->id == other.id);
}