#include <iostream>	
using namespace std;

class SoSimple {
private:
	int num;
public:
	SoSimple(int n) : num(n) {
		cout << "New Object: " << this << endl;
	}
	SoSimple(const SoSimple & copy) : num(copy.num) {
		cout << "New Copy obj: " << this << endl;
	}
	~SoSimple() {
		cout << "Destroy obj: " << this << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob) {
	cout << "Parm ADR: " << &ob << endl;
	return ob;
}

int main(void) {
	SoSimple obj(7);
	SimpleFuncObj(obj);

	cout << endl;
	SoSimple tempRef = SimpleFuncObj(obj);
	cout << "Return Obj" << &tempRef << endl;
	return 0;
}

/*
복사 생성자의 호출시점
1: 기존에 생성된 객체를 이용해서 새로운 객체를 초기화 하는경우
2: Call-by-value 방식의 함수호출 과정에서 객체를 인자로 전달하는 경우
3: 객체를 반환하되, 참조형으로 반환하는 경우

New Object : 0019F8C0
New Copy obj : 0019F7A8
Parm ADR : 0019F7A8
New Copy obj : 0019F7DC
Destroy obj : 0019F7A8
Destroy obj : 0019F7DC

New Copy obj : 0019F7A8
Parm ADR : 0019F7A8
New Copy obj : 0019F8B4
Destroy obj : 0019F7A8
Return Obj0019F8B4
Destroy obj : 0019F8B4
Destroy obj : 0019F8C0
*/