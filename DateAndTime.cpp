#include <iostream>
using namespace std;

#include "DateAndTime.h"

DateAndTime::DateAndTime(int day, int month, int year, int minute, int hour) : Date(day, month, year)
{
	this->minute = minute;
	this->hour = hour;
}

ostream& operator<<(ostream& os, const DateAndTime& d)
{
	os << (Date)d << " ---- " << (d.hour < 10 ? "0" : "") << d.hour << ":" << (d.minute < 10 ? "0" : "") << d.minute << "\n";
	return os;
}