#include <iostream>
using namespace std;

void Adder(int& x) {
	x++;
	return;
}

void InverSign(int& x) {
	x = -x;
	return;
}

int main(void) {
	int a = 10;
	cout << a << endl;
	Adder(a);
	cout << a << endl;
	InverSign(a);
	cout << a << endl;
}