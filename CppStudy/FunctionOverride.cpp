#include <iostream>
using namespace std;

class First {
public:
	void MyFunc() {
		cout << "FirstFunc" << endl;
	}
};

class Second : public First {
public:
	void MyFunc() {
		cout << "SecondFunc" << endl;
	}
};

class Third : public Second {
public:
	void MyFunc() {
		cout << "ThirdFunc" << endl;
	}
};

int main(void) {
	Third * tptr = new Third();
	Second * sptr = tptr;
	First * fptr = sptr;

	//포인터의 자료형을 기반으로 호출대상을 결정함.
	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	delete tptr;
	return 0;
}