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
	키워드 explicit으로 묵시적 변환을 막을 수 있음
	
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
	cout << "생성 및 초기화 직전" << endl;
	SoSimple sim2 = sim1; // SoSimple sim2(sim1) 로 변환
	cout << "생성 및 초기화 직후" << endl;
	sim2.ShowSimpleDate();
	return 0;
}
