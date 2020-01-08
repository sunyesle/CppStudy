#include <iostream>
using namespace std;

class Calculator {
private:
	int addCount;
	int divCount;
	int minCount;
	int mulCount;

public :
	int Add(int x, int y);
	int Min(int x, int y);
	int Mul(int x, int y);
	int Div(int x, int y);
	void Init(); 
	void ShowOpCount();
};

int Calculator::Add(int x, int y) {
	addCount++;
	return x + y;
}

int Calculator::Min(int x, int y)
{
	minCount++;
	return x-y;
}

int Calculator::Mul(int x, int y)
{
	mulCount++;
	return x*y;
}

int Calculator::Div(int x, int y)
{
	divCount++;
	return x/y;
}

void Calculator::Init()
{
	addCount = 0;
	divCount = 0;
	minCount = 0;
	mulCount = 0;
}

void Calculator::ShowOpCount()
{
	cout << "µ¡¼À:" << addCount << " »¬¼À:" << minCount << " °ö¼À:" << mulCount << " ³ª´°¼À:" << divCount << endl;
}

int main(void) {
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7  = " << cal.Div(3.5 ,1.7) << endl;
	cout << " 2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}

