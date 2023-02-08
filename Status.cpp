#include <iostream>
using namespace std;

#include "Status.h"

Status::Status(const char* content, const DateAndTime& publish) : publish(publish)
{
	this->content = new char[strlen(content) + 1];
	strcpy(this->content, content);
}

Status::~Status()
{
	delete[] content;
}

ostream& operator<<(ostream& os, const Status& s)
{
	os << "Status's content: ''" << s.content << "''" << "\n";
	os << "Publish date: ";
	os << s.publish;
	return os;
}
