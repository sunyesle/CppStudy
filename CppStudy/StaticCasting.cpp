#include <iostream>
using namespace std;

class Car
{
private:
	int fuelGauge;
public:
	Car(int fuel) : fuelGauge(fuel)
	{}
	void ShowCarState() { cout << "�ܿ� ���ᷮ: " << fuelGauge << endl; }
};

class Truck : public Car
{
private:
	int freightWeight;
public:
	Truck(int fuel, int weight)
		: Car(fuel), freightWeight(weight)
	{}
	void ShowTruckState()
	{
		ShowCarState();
		cout << "ȭ���� ����: " << freightWeight << endl;
	}
};

// static_cast : ��Ӱ��迡 �ִ� Ŭ������ ������ �� ������ �������� ����ȯ or �⺻�ڷ��� �������� ����ȯ

int main(void)
{
	Car * pcar1 = new Truck(80, 200);
	Truck * ptruck1 = static_cast<Truck*>(pcar1);
	ptruck1->ShowTruckState();
	cout << endl;

	Car * pcar2 = new Car(120);	
	Truck * ptruck2 = static_cast<Truck*>(pcar2);
	ptruck2->ShowTruckState();

	double result = static_cast<double>(20) / 3;
	return 0;
}