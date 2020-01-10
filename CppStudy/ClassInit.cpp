#include <iostream>	
using namespace std;

class SoSimple {
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2)
		: num1(n1) , num2(n2){

	}
	SoSimple(SoSimple &copy)
		: num1(copy.num1), num2(copy.num2) {
		cout << "Called SoSimple(SoSimple &copy)" << endl;
	}
	/*
	explicit SoSimple(SoSimple &copy)
		: num1(copy.num1), num2(copy.num2) {
		cout << "Called SoSimple(SoSimple &copy)" << endl;
	}
	Ű���� explicit���� ������ ��ȯ�� ���� �� ����
	
	SoSimple sim2 = sim1;	(x)
	SoSimple sim2(sim1);	(o)

	*/
	void ShowSimpleDate() {
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main(void) {
	SoSimple sim1(12, 24);
	cout << "���� �� �ʱ�ȭ ����" << endl;
	SoSimple sim2 = sim1; // SoSimple sim2(sim1) �� ��ȯ
	cout << "���� �� �ʱ�ȭ ����" << endl;
	sim2.ShowSimpleDate();
	return 0;
}
