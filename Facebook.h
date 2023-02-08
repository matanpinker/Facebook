#ifndef __FACEBOOK_H
#define __FACEBOOK_H

#pragma warning(disable: 4996)
#include "Account.h"
#include "DateAndTime.h"
#include "status.h"
#include "FanPage.h"
#include "Friend.h"
#include "Titles.h"

#include <vector>


class Facebook
{
private:	
	std::vector<Friend*> allFriends;
	std::vector<FanPage*> allFanPages;

public:
	Facebook();

	
	void AttributStatusToFriend(const char* content, const DateAndTime& theDate, int FriendNum);
	void attributStatusToFanPage(const char* content, const DateAndTime& theDate , int FanPageNum);
	
	
	friend ostream& operator<<(ostream& os, const Facebook& s);
	void operator+=(Friend* theFriend);
	void operator+=(FanPage* theFanPage);

	void ShowStatusesOfFriend(int FriendNum) const;
	void ShowStatusesOfFanPage(int FanPageNum) const;
	void printListOfFriends() const;
	void printListOfFanPages() const;
	
	void printListOfFriendsToLink(int friendID) const;
	bool LinkBetweenTwoFriends(int friend1ID, int friend2ID);

	void printListOfFriendsToUnLink(int friendID) const;
	bool CancleLinkBetweenTwoFriends(int friend1ID, int friend2ID);

	void ShowLastTenStatusesOfFriend(int NumFriend) const;

	bool printListOfFanPagesToLink(int friendID) const;
	bool linkBetweenFriendAndFanPage(int friendID, int fanPageID);

	bool unLinkBetweenFriendAndFanPage(int friendID, int fanPageID);
	bool PrintListOfFanPagesToUnlink(int friendID) const;

	Friend* getFriendById(int id) const;
	FanPage* getFanPageById(int id) const;

	bool friendIsNotFriendWithAll(int friendID) const;
	bool friendHasSomeFriends(int friendID) const;
	bool validFriendID(int id) const;
	bool validFanPageID(int id) const;

	void showMyFriends(int friendID) const;

};

#endif //__FACEBOOK_H