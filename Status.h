#ifndef __STATUS_H
#define __STATUS_H

#pragma warning(disable: 4996)

//class FanPage; // WE HAVE FRIEND** SO WE NEED FORWARD DECLARION
//class Status; // WE HAVE STATUS** SO WE NEED FORWARD DECLARION

#include "DateAndTime.h" //We use ShowDateAndTime(), so we need this

#include <vector>

class Status
{
private:
	char* content;
	DateAndTime publish;
public:
	Status(const char* content, const DateAndTime& publish);
	~Status();

	friend ostream& operator<<(ostream& os, const Status& s);
};

#endif //__STATUS_H