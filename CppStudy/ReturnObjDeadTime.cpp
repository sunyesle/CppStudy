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
���� �������� ȣ�����
1: ������ ������ ��ü�� �̿��ؼ� ���ο� ��ü�� �ʱ�ȭ �ϴ°��
2: Call-by-value ����� �Լ�ȣ�� �������� ��ü�� ���ڷ� �����ϴ� ���
3: ��ü�� ��ȯ�ϵ�, ���������� ��ȯ�ϴ� ���

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