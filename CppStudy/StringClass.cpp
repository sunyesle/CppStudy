#include "StringClass.h"

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
	char * tempstr = new char[len+s.len -1];
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
	return strcmp(string,str.string)? false: true;
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

int main(void) {
	String str1 = "I like ";
	String str2 = "string class";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3)
		cout << "동일 문자열" << endl;
	else
		cout << "동일하지 않은 문자열!" << endl;

	String str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;
	return 0;
}