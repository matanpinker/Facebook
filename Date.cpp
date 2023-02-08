#include <iostream>
using namespace std;

#include "Date.h"

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

ostream& operator<<(ostream& os, const Date& d)
{
	os << (d.day < 10 ? "0" : "") << d.day << "/" << (d.month < 10 ? "0" : "") << d.month << "/" << d.year;
	return os;
}