#include <iostream>
using namespace std;

#include "Facebook.h"



Facebook::Facebook()
{
	allFriends = vector<Friend*>();
	allFanPages = vector<FanPage*>();
}

void Facebook::AttributStatusToFriend(const char* content, const DateAndTime& theDate, int friendID)
{
	Friend* friendById = getFriendById(friendID);
	if (friendById != NULL) // cheking if the friend exist
	{
		Status* theStatus = new Status(content, theDate);
		friendById->addStatus(theStatus); // adding the status to the friend
		cout << "The status has been successfully uploaded and belongs to the friend: ";
		cout << friendById->getName() << "\n"; // print the name of to the friend we added the status to
	}
	else
	{
		cout << "No friend found in ID " << friendID << ", there are only " << allFriends.size() << " friends!\n";
	}
}

void Facebook::attributStatusToFanPage(const char* content, const DateAndTime& theDate, int fanPageID)
{
	FanPage* fanPageById = getFanPageById(fanPageID);
	if (fanPageById != NULL)
	{
		Status* theStatus = new Status(content, theDate);
		fanPageById->addStatus(theStatus);
		cout << "The status has been successfully uploaded and belongs to the fanpage: ";
		cout << fanPageById->getName() << "\n";
	}
	else {
		cout << "No fanpage found in ID " << fanPageID << ", there are only " << allFanPages.size() << " fanpages!\n";
	}
}

ostream& operator<<(ostream& os, const Facebook& facebook)
{
	// show all friends
	os << "Facebook has " << facebook.allFriends.size() << " friends:\n";
	for (const auto& f : facebook.allFriends)
	{
		os << *f;
		f->showStatuses();
		os << "------------------------\n";
	}

	os << "\n";

	// show all fanpages
	os << "Facebook has " << facebook.allFanPages.size() << " FanPages:\n";
	for (const auto& fp : facebook.allFanPages)
	{
		os << *fp;
		fp->showStatuses();
		os << "------------------------\n";
	}
	return os;
}

void Facebook::ShowStatusesOfFriend(int friendID) const
{
	Friend* friendById = getFriendById(friendID);
	if (friendById != NULL) // cheking if the friend exist
	{
		cout << "The friend: " << friendById->getName() << "\n";
		friendById->showStatuses();
		cout << buffer2;
	}
}

void Facebook::ShowStatusesOfFanPage(int fanPageID) const
{
	const FanPage* fanPageById = getFanPageById(fanPageID);
	if (fanPageById != NULL) // cheking if the fanpage exist
	{
		cout << "The fanpage: " << fanPageById->getFanPageName() << "\n";
		fanPageById->showStatuses();
		cout << buffer2;
	}
}


void Facebook::printListOfFriends() const
{
	// Iterate through the vector of friends
	for (const auto& f : allFriends)
	{
		cout << f->getName() << " (ID:" << f->getFriendID() << ")" << "\n";
	}
}

void Facebook::printListOfFanPages() const
{
	for (const auto& f : allFanPages)
	{
		cout << f->getName() << " (ID:" << f->getFanPageID() << ")" << "\n";
	}
}

bool Facebook::friendIsNotFriendWithAll(int friendID) const
{
	Friend* theFriend = getFriendById(friendID);
	if (theFriend->getNumOfFriends() == allFriends.size()-1)
		return false;
	else return true;
}

bool Facebook::LinkBetweenTwoFriends(int friend1ID, int friend2ID)
{
	if (!validFriendID(friend2ID))
	{
		cout << Friend_2_ID_Doesnt_Exist;
		return false;
	}

	if (friend1ID == friend2ID) // if the friend is not himself
	{
		cout << Cannot_Link_Friend_To_Himself;
		return false;
	}

	Friend* friend1 = getFriendById(friend1ID);
	Friend* friend2 = getFriendById(friend2ID);

	if (friend1->friendExist(friend2)) //if the friend is already linked
	{
		cout << Friends_Already_linked;
		return false;
	}

		friend1->linkFriend(friend2);
		friend2->linkFriend(friend1);
		return true;
}

bool Facebook::friendHasSomeFriends(int friendID) const
{
	Friend* theFriend = getFriendById(friendID);
	if (theFriend->myFriends.empty())
		return false;
	else return true;
}

bool Facebook::CancleLinkBetweenTwoFriends(int friend1ID, int friend2ID)
{
	if (!validFriendID(friend2ID))
	{
		cout << Friend_2_ID_Doesnt_Exist;
		return false;
	}

	if (friend1ID == friend2ID)
	{
		cout << "Cannot Cancle the same friend from himself!\n";
		return false;
	}

	Friend* friend1 = getFriendById(friend1ID);
	Friend* friend2 = getFriendById(friend2ID);

	if (!friend1->friendExist(friend2)) //if the friend is already linked
	{
		cout << This_Friends_Are_Not_Friends;
		return false;
	}

	friend1->unLinkFriend(friend2);
	friend2->unLinkFriend(friend1);
	return true;
}

void Facebook::printListOfFriendsToLink(int friendID) const
{
	Friend* theFriend = getFriendById(friendID);
	for (const auto f : allFriends)
	{
		if (theFriend != f && !theFriend->friendExist(f))
		{
			cout << f->getName() << " (ID " << f->getFriendID() << ")" << "\n";
		}
	}
}

void Facebook::printListOfFriendsToUnLink(int friendID) const
{
	Friend* theFriend = getFriendById(friendID);
	for (const auto f : allFriends)
	{
		if (theFriend != f && theFriend->friendExist(f))
		{
			cout << f->getName() << " (ID " << f->getFriendID() << ")" << "\n";
		}
	}
}

void Facebook::ShowLastTenStatusesOfFriend(int friendID) const
{
	int count=0;
	int j = 0;
	Friend* friendById = getFriendById(friendID);
	int num = friendById->myFriends.size();
	while (count<10 && count>=j) //in case of less then 10 statuses, j will be grater then count, and we prevent infinite loop
	{
		for (int i = 0; i < num ; i++) //run over the friends of the friend
		{
			Friend* current = friendById->getFriendByIndex(i);
			if (current->myStatuses.size()>j && current != nullptr) //for case of 0 statuses per friend or 
			{
				cout << "Status #" << count + 1 << " By " << current->getName() << ":\n";
				cout << *current->getStatusByIndex(j);
			}
			count++;
			if (count == 10)
				break;
		}
		j++;
	}
}

bool Facebook::printListOfFanPagesToLink(int friendID) const
{
	Friend* theFriend = getFriendById(friendID);
	if (theFriend->getNumOfFanPages() == allFanPages.size())
	{
		return false;
	}
	else
	{
		cout << enter_The_ID_Of_The_FanPage_To_Link;
		for (const auto fp : allFanPages)
		{
			if (!theFriend->fanPageExist(fp))
			{
				cout << fp->getFanPageName() << " (ID " << fp->getFanPageID() << ")" << "\n";
			}
		}
		return true;
	}
}

bool Facebook::linkBetweenFriendAndFanPage(int friendID, int fanPageID)
{
	if (!validFanPageID(fanPageID))
	{
		cout << FanPage_ID_Doesnt_Exist;
		return false;
	}

	Friend* friend1 = getFriendById(friendID);
	FanPage* fanpage = getFanPageById(fanPageID);
	//FanPage fp = *fanpage;

	if (friend1->fanPageExist(fanpage)) //if the friend is already linked to the fanpage
	{
		cout << Friend_And_FanPage_Already_Linked;
		return false;
	}

	friend1->linkFanPage(fanpage);
	fanpage->linkFriend(friend1);
	return true;
}

bool Facebook::PrintListOfFanPagesToUnlink(int friendID) const
{
	Friend* theFriend = getFriendById(friendID);
	if (theFriend->myFanPages.empty())
	{
		return false;
	}
	else
	{
		cout << enter_The_ID_Of_The_FanPage_To_Unlink;
		for (const auto& fp : theFriend->myFanPages)
		{
				cout << fp->getFanPageName() << " (ID " << fp->getFanPageID() << ")" << "\n";
		}
		return true;
	}
}

bool Facebook::unLinkBetweenFriendAndFanPage(int friendID, int fanPageID)
{
	Friend* friend1 = getFriendById(friendID);
	FanPage* fanpage = getFanPageById(fanPageID);

	if (friend1 == nullptr)
	{
		cout << Friend_ID_Doesnt_Exist;
		return false;
	}
	if (fanpage == nullptr)
	{
		cout << FanPage_ID_Doesnt_Exist;
		return false;
	}
	if (!friend1->fanPageExist(fanpage))
	{
		cout << Friend_And_FanPage_Not_Linked;
		return false;
	}

	friend1->unLinkFanPage(fanpage);
	fanpage->unLinkFriend(friend1);
	return true;
}

Friend* Facebook::getFriendById(int id) const
{
	for (auto& friendPointer : allFriends)
	{
		if (friendPointer->getFriendID() == id)
			return friendPointer;
	}
	return nullptr;
}

FanPage* Facebook::getFanPageById(int id) const
{
	for (const auto fp : allFanPages)
	{
		if (fp->getFanPageID() == id)
		{
			return fp;
		}
	}
	return nullptr;
}

bool Facebook::validFriendID(int id) const
{
	if (id >= 1000 && id < (allFriends.size()+1000))
		return true;
	else return false;
}

bool Facebook::validFanPageID(int id) const
{
	if (id >= 2000 && id < (allFanPages.size()+2000))
		return true;
	else return false;
}

void Facebook::showMyFriends(int id) const
{
	Account* theaccount = getFriendById(id);
	if (theaccount == nullptr)
	{
		theaccount = getFanPageById(id);
		if (theaccount == nullptr)
		{
			cout << "No friend or fanpage found with ID: " << id << endl;
			return;
		}
	}
	if (theaccount->myFriends.empty())
	{
		cout << "The friend/fanpage " << theaccount->getName() << " has no friends/fans. :(\n";
	}
	else
	{
		cout << "The friends/fans of " << theaccount->getName() << " are: \n";
		for (const auto& accountPointer : theaccount->myFriends)
		{
			cout << accountPointer->getName() << " (ID:" << accountPointer->getFriendID() << ")\n";
		}
	}
}

void Facebook::operator+=(Friend* theFriend)
{
	{
		allFriends.push_back(theFriend);
		cout << "The friend " << allFriends.back()->getName() << " Added successfully. His/Her ID is: " << allFriends.back()->getFriendID() << "\n";
	}
}

void Facebook::operator+=(FanPage* theFanPage)
{
		allFanPages.push_back(theFanPage);
		cout << "The fanpage " << allFanPages.back()->getName() << " Added successfully. ID is: " << allFanPages.back()->getFanPageID() << "\n";
}