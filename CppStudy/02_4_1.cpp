#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
using namespace std;

int main(void) {
	char *str1 = "ABC 123 ";
	char *str2 = "sys 9923 ";
	char str3[50];
	
	cout << strlen(str1) << " " << strlen(str2) << endl;
	strcpy(str3, str1);
	strcat(str3, str2);
	cout << str3 << endl;
	cout << strcmp(str1, str2) << endl;

}