#include <iostream>	
using namespace std;

void main(void) {
	const int num = 12;
	const int * ptr = &num;
	const int * (&ref) = ptr;

	cout << *ptr << endl;
	cout << *ref << endl;

}