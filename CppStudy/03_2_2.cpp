#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Printer {
private:
	char string[100];

public :
	void SetString(char* str);
	void ShowString();
};

void Printer::SetString(char* str)
{
	strcpy(string, str);
}

void Printer::ShowString()
{
	cout << string << endl;
}

int main(void) {
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();
	return 0;
}