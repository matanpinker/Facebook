#include <iostream>
using namespace std;

#include "Facebook.h"

int enterDay();
int enterMonth();
int enterYear();
int enterHour();
int enterMinute();

int main()
{
	Facebook facebook;
	facebook += new Friend("Yaron", Date(17, 1, 1992));
	facebook += new Friend("Matan", Date(28, 6, 1995));
	facebook += new Friend("Tal", Date(19, 2, 1996));
	facebook += new Friend("Eden", Date(1, 1, 2000));
	facebook += new Friend("Ori", Date(12, 12, 2012));
	facebook += new Friend("Irena", Date(10, 10, 1910));


	facebook += new FanPage("Afeka");
	facebook += new FanPage("Google");
	facebook += new FanPage("StateOfIsrael");

	DateAndTime stamDate(1, 1, 2001, 1, 1);
	facebook.AttributStatusToFriend("Blabla", stamDate, 1000);
	facebook.AttributStatusToFriend("My name is Yaron", stamDate, 1000);
	facebook.AttributStatusToFriend("Hello", stamDate, 1000);
	facebook.AttributStatusToFriend("Hahaha", stamDate, 1000);
	facebook.AttributStatusToFriend("Ma nishma?", stamDate, 1001);
	facebook.AttributStatusToFriend("Ma kore?", stamDate, 1001);
	facebook.AttributStatusToFriend("Ma hamatsav?", stamDate, 1002);
	facebook.AttributStatusToFriend("I have a question", stamDate, 1002);
	facebook.AttributStatusToFriend("Yoohooo", stamDate, 1004);
	facebook.AttributStatusToFriend("Israel is so beautiful!", stamDate, 1004);
	facebook.AttributStatusToFriend("I wanna eat cake!", stamDate, 1004);
	facebook.AttributStatusToFriend("I'm tired", stamDate, 1005);
	facebook.AttributStatusToFriend("I have the best time of my life!!!", stamDate, 1005);

	DateAndTime stamDate2(2, 2, 2002, 2, 2);
	facebook.attributStatusToFanPage("We happy to open the new semester, Good luck to all students", stamDate2 ,2000);
	facebook.attributStatusToFanPage("Wellcome to MAPAT AMAL", stamDate2, 2000);
	facebook.attributStatusToFanPage("We are hire!", stamDate2, 2001);
	facebook.attributStatusToFanPage("Good morning", stamDate2, 2001);
	facebook.attributStatusToFanPage("So fun to born", stamDate2, 2002);
	facebook.attributStatusToFanPage("Come to visit in Israel", stamDate2, 2002);


	bool bool1 = facebook.LinkBetweenTwoFriends(1003, 1000);
	bool bool2 = facebook.LinkBetweenTwoFriends(1003, 1001);
	bool bool3 = facebook.LinkBetweenTwoFriends(1003, 1002);
	bool bool4 = facebook.LinkBetweenTwoFriends(1003, 1004);
	bool bool5 = facebook.LinkBetweenTwoFriends(1003, 1005);


	cout << buffer2;
	int exit = 0;
	int answer;
	
		while (exit == 0)
		{
			cout << buffer1;
			cout << main_Menu;
			cout << menu_Option1;
			cout << menu_Option2;
			cout << menu_Option3;
			cout << menu_Option4;
			cout << menu_Option5;
			cout << menu_Option6;
			cout << menu_Option7;
			cout << menu_Option8;
			cout << menu_Option9;
			cout << menu_Option10;
			cout << menu_Option11;
			cout << menu_Option12;
			cin >> answer;
			switch (answer)
			{
			case 1:
			{
				char name[20];
				int day=0, month=0, year=0;

				cout << enter_Friends_Name;
				cin >> name;
				cout << enter_Friends_Birth_Date;

				Date tmpdate(enterDay(), enterMonth(), enterYear());
				//facebook.AddFriend(name, tmpdate);

				facebook += new Friend (name, tmpdate);
				break;
			} //case 1

			case 2:
			{
				char name[20];
				cout << enter_Fan_Pages_Name;
				cin >> name;
				facebook += new FanPage(name);
				break;
			} //case 2

			case 3:
			{
				int FriendOrFanPage = 0;
				char content[10000] = "";
				int writerID = 0;
				int day = 0, month = 0, year = 0, hour=0, minute =0;
				cout << add_Status_To_Friend_Or_Fan_Page;
				cin >> FriendOrFanPage;
				switch (FriendOrFanPage)
				{
				case 1:
				{
					cout << enter_Statuses_Publish_Date;
					DateAndTime tmpdateandtime(enterDay(), enterMonth(), enterYear(), enterMinute(), enterHour());

					cout << enter_ID_Of_The_Writer_Friend;
					facebook.printListOfFriends();
					cin >> writerID;
					cout << enter_the_content_of_the_status;
					cin.ignore();
					cin.get(content, 10000);

					facebook.AttributStatusToFriend(content, tmpdateandtime, writerID);
					break;
				} //case 1 - Friend or FanPage
				case 2:
				{
					cout << enter_Statuses_Publish_Date;
					DateAndTime tmpdateandtime(enterDay(), enterMonth(), enterYear(), enterMinute(), enterHour());

					cout << enter_ID_Of_The_Writer_Fan_Page;
					facebook.printListOfFanPages();
					cin >> writerID;
					cout << enter_the_content_of_the_status;
					cin.ignore();
					cin.get(content, 10000);
					facebook.attributStatusToFanPage(content, tmpdateandtime, writerID);
					break;
				} //case 2 - Friend or FanPage
				default:
				{
					cout << invalid_Option;
					break;
				} //default - Friend or FanPage
				} //switch - Friend or FanPage
				break;
			} //case 3


			case 4: //Show all the statuses of a friend or fanpage
			{
				int FriendOrFanPage = 0;
				int writerID = 0; // the serial number of the friend / fanpage
				cout << show_Status_of_Friend_Or_Fan_Page;
				cin >> FriendOrFanPage;
				switch (FriendOrFanPage)
				{
				case 1: //friend
				{
					cout << enter_ID_Of_The_Writer_Friend;
					facebook.printListOfFriends();
					cin >> writerID;
					facebook.ShowStatusesOfFriend(writerID);
					break;
				} //case 1
				case 2: //fanpage
				{
					cout << enter_ID_Of_The_Writer_Fan_Page;
					facebook.printListOfFanPages();
					cin >> writerID;
					facebook.ShowStatusesOfFanPage(writerID);
					break;
				} //case 2
				default:
					cout << invalid_Option;
					break;
				} //default
				break;
			} //case 4

			case 5:
			{
				int writerID;
				cout << enter_The_ID_Of_The_Friend_Who_You_Want_To_See_His_Wall;
				facebook.printListOfFriends();
				cin >> writerID;
				facebook.ShowLastTenStatusesOfFriend(writerID);
				break;
			} //case6

			case 6: //Show all the friends and fanpages
			{
				cout << facebook;
				break;
			} //case6

			case 7: //Link between 2 friends
			{
				int friend1ID, friend2ID;
				bool tmp = false;
				while (!tmp)
				{
					cout << enter_The_ID_Of_The_First_Friend;
					facebook.printListOfFriends();
					cout << press_1_To_Go_Back_To_Main_Menu;
					cin >> friend1ID;
					if (friend1ID != 1)
					{
						if (!facebook.validFriendID(friend1ID))
						{
							cout << Friend_1_ID_Doesnt_Exist;
						}
						else if (facebook.friendIsNotFriendWithAll(friend1ID))
						{
							cout << enter_The_ID_Of_The_Friend_You_Want_To_Link;
							facebook.printListOfFriendsToLink(friend1ID);
							cin >> friend2ID;
							tmp = facebook.LinkBetweenTwoFriends(friend1ID, friend2ID);
						}
						else
						{
							cout << Friend_1_Is_Friend_With_All_The_Friends_On_Facebook;
						}
					}
					else break;
				}
				break;
			} //case7

			case 8: //Cancle friendship between 2 friends
			{
				int friend1ID, friend2ID;
				bool tmp = false;
				while (!tmp)
				{
					cout << enter_The_ID_Of_The_First_Friend;
					facebook.printListOfFriends();
					cout << press_1_To_Go_Back_To_Main_Menu;
					cin >> friend1ID;
					if (friend1ID != 1)
					{
						if (!facebook.validFriendID(friend1ID))
						{
							cout << Friend_1_ID_Doesnt_Exist;
						}
						else if (facebook.friendHasSomeFriends(friend1ID))
						{
							cout << enter_The_ID_Of_The_Friend_You_Want_To_Unlink;
							facebook.printListOfFriendsToUnLink(friend1ID);
							cin >> friend2ID;
							tmp = facebook.CancleLinkBetweenTwoFriends(friend1ID, friend2ID);
						}
						else
						{
							cout << Friend_1_Has_No_Friends_At_All;
						}
					}
					else
						break;
				} //while
				break;
			} //case8

			case 9: //Link FanPage to Friend
			{
				int friendID, fanPageID;
				bool tmp = false;
				while (!tmp)
				{
					cout << enter_The_ID_Of_The_First_Friend;
					facebook.printListOfFriends();
					cout << press_1_To_Go_Back_To_Main_Menu;
					cin >> friendID;
					if (friendID != 1)
					{
						if (!facebook.validFriendID(friendID))
						{
							cout << Friend_ID_Doesnt_Exist;
						}
						else if (!facebook.printListOfFanPagesToLink(friendID)) //check if this friend is already follow all fanpages in facebook
						{
							cout << Friend_Is_Fan_Of_All_The_FanPages;
						}
						else
						{
							cin >> fanPageID;
							tmp = facebook.linkBetweenFriendAndFanPage(friendID, fanPageID);
						}
					}
					else
						break;
				}
				break;
			} //case9

			case 10: //UnLink FanPage from Friend
			{
				int friendID, fanPageID;
				bool tmp = false;
				while (!tmp)
				{

						cout << enter_The_ID_Of_The_Friend;
						facebook.printListOfFriends();
						cout << press_1_To_Go_Back_To_Main_Menu;
						cin >> friendID;
						if (friendID != 1)
						{
							if (!facebook.validFriendID(friendID))
							{
								cout << Friend_1_ID_Doesnt_Exist;
							}
							else if (!facebook.PrintListOfFanPagesToUnlink(friendID))
							{
								cout << friend_Has_No_FanPages;
							}
							else
							{
								cin >> fanPageID;
								tmp = facebook.unLinkBetweenFriendAndFanPage(friendID, fanPageID);
							}
						}
						else
							break;
				}
				break;
			} //case10

			case 11:
			{
				int id = 0;
				bool validAnswer = true;
				while (!(facebook.validFriendID(id) || facebook.validFanPageID(id)))
				{
					if (!validAnswer)
					{
						cout << ID_Not_Valid;
						cout << buffer2;
					}
					cout << Enter_The_ID_Of_The_Friend_Or_Fanpage_To_See_His_Friends_List;
					facebook.printListOfFriends();
					facebook.printListOfFanPages();
					cin >> id;
					validAnswer = false;
				}
				facebook.showMyFriends(id);
				cout << buffer2;
				break;
			}
			default: //exit from the menu
			{
				cout << have_A_Nice_Day;
				exit = 1;
				break;
			}
			} //switch
		} //while
		system("pause");

		return 0;
} //main

int enterDay()
{
	int day;
	bool res = false;
	do {
		cout << enter_Day;
		cin >> day;
		if (day < 1 || day > 31)
		{
			cout << day_Error_Value;
			res = false;
		}
		else
		{
			res = true;
		}
	} while (res != true);
	return day;
}

int enterMonth()
{
	int month;
	bool res = false;
	do {
		cout << enter_Month;
		cin >> month;
		if (month < 1 || month > 12)
		{
			cout << month_Error_Value;
			res = false;
		}
		else
		{
			res = true;
		}
	} while (res != true);
	return month;
}

int enterYear()
{
	int year;
	bool res = false;
	do {
		cout << enter_Year;
		cin >> year;
		if (year < 1900 || year > 2023)
		{
			cout << year_Error_Value;
			res = false;
		}
		else
		{
			res = true;
		}
	} while (res != true);
	return year;
}

int enterHour()
{
	int hour;
	bool res = false;
	do {
		cout << enter_Hour;
		cin >> hour;
		if (hour < 0 || hour > 23)
		{
			cout << hour_Error_Value;
			res = false;
		}
		else
		{
			res = true;
		}
	} while (res != true);
	return hour;
}

int enterMinute()
{
	int minute;
	bool res = false;
	do {
		cout << enter_Minute;
		cin >> minute;
		if (minute < 0 || minute > 59)
		{
			cout << minute_Error_Value;
			res = false;
		}
		else
		{
			res = true;
		}
	} while (res != true);
	return minute;
}