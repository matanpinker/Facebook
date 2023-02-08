#ifndef __DATE_H
#define __DATE_H

#pragma warning(disable: 4996)

class Date
{
protected:
	int day;
	int month;
	int year;

public:
	Date(int day, int month, int year);

	friend ostream& operator<<(ostream& os, const Date& s);
};
#endif //__DATE_H