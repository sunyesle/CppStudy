#include <iostream>
using namespace std;

class First {
public:
	virtual void MyFunc() {
		cout << "FirstFunc" << endl;
	}
};

class Second : public First {
public:
	virtual void MyFunc() {
		cout << "SecondFunc" << endl;
	}
};

class Third : public Second {
public:
	virtual void MyFunc() {
		cout << "ThirdFunc" << endl;
	}
};

int main(void) {
	Third * tptr = new Third();
	Second * sptr = tptr;
	First * fptr = sptr;

	// 함수가 가상함수로 선언되면, 해당함수 호출 시,
	// 포인터 변수가 실제로 가르키는 객체를 참조하여 호출의 대상을 결정함
	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	delete tptr;
	return 0;
}