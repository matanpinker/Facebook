#ifndef __FRIEND_H
#define __FRIEND_H

#pragma warning(disable: 4996)

#include "FanPage.h"
#include "Date.h"
#include "Status.h" //We use functions from Status (for example: "ShowStatus"), so we need the include
#include "Account.h"



class Friend : public Account
{
private:
	static int counter;
	int id;
	Date birthDate;

public:
	std::vector<FanPage*> myFanPages;
	Friend(const char* theName, const Date& BirthDate);

	virtual void showStatuses() const override;
	
	void linkFanPage(FanPage* theFanPage);
	void unLinkFanPage(FanPage* theFanPage);

	int getNumOfFanPages() const;
	int getFriendID() const;

	char* getName() const;

	friend ostream& operator<<(ostream& os, const Friend& theFriend);
	bool operator<(const Friend& other) const;
	bool fanPageExist(const FanPage* fp) const;

	bool friendExist(const Friend* theFriend) const;

};

#endif //__FRIEND_H
