#ifndef __FANPAGE_H
#define __FANPAGE_H

#pragma warning(disable: 4996)

#include "Friend.h"
#include "Status.h" //We use functions from Status (for example: "ShowStatus"), so we need the include
#include "Account.h"

class FanPage : public Account
{
private:	
	static int counter;
	int id;

public:

	FanPage(const char* theName);
	~FanPage();

	char* getFanPageName() const;

	int getFanPageID() const;

	virtual void showStatuses() const;

	friend ostream& operator<<(ostream& os, const FanPage& theFanPage);
	bool operator==(const FanPage& other) const;

};

#endif //__FANPAGE_H
