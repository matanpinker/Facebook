#ifndef __DATEANDTIME_H
#define __DATEANDTIME_H

#pragma warning(disable: 4996)

#include "Date.h"

class DateAndTime: public Date
{
private:
	int hour;
	int minute;

public:
	DateAndTime(int day, int month, int year, int minute, int hour);

	friend ostream& operator<<(ostream& os, const DateAndTime& s);
};

#endif //__DATEANDTIME_H