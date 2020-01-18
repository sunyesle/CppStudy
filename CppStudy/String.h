#ifndef __STRING__
#define __STRING__

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
	int len;
	char * string;
public:
	String();
	String(const char * s);
	String(const String& s);
	String& operator= (const String& s);
	String& operator+= (const String& s);
	String operator+ (const String& s);
	bool operator==(const String& s);
	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);
	~String();
};

#endif // !__STRING_CLASS__
