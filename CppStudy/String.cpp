#include "String.h"

String::String()
{
	len = 0;
	string = NULL;
}

String::String(const char * s)
{
	len = strlen(s) + 1;
	string = new char[len];
	strcpy(string, s);
}

String::String(const String & s)
{
	len = s.len;
	string = new char[len];
	strcpy(string, s.string);
}

String & String::operator=(const String & s)
{
	if (string != NULL)
		delete[] string;
	len = s.len;
	string = new char[len];
	strcpy(string, s.string);
	return *this;
}

String String::operator+(const String & s)
{
	char * tempstr = new char[len + s.len - 1];
	strcpy(tempstr, string);
	strcat(tempstr, s.string);

	String temp(tempstr);
	delete[]tempstr;
	return temp;
}

String & String::operator+=(const String & s)
{
	len += (s.len - 1);
	char * tempstr = new char[len];
	strcpy(tempstr, string);
	strcat(tempstr, s.string);

	if (string != NULL)
		delete[] string;

	string = tempstr;
	return *this;;
}

bool String::operator==(const String & str)
{
	return strcmp(string, str.string) ? false : true;
}

String::~String()
{
	delete[] string;
}

ostream & operator<<(ostream & os, const String & str)
{
	os << str.string;
	return os;
}

istream & operator>>(istream & is, String & s)
{
	char input[100];
	is >> input;
	s = String(input);
	return is;
}