#include <iostream>
using namespace std;

class Car
{
private:
	int fuelGauge;
public:
	Car(int fuel) : fuelGauge(fuel)
	{}
	void ShowCarState() { cout << "잔여 연료량: " << fuelGauge << endl; }
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
		cout << "화물의 무게: " << freightWeight << endl;
	}
};

// static_cast : 상속관계에 있는 클래스의 포인터 및 참조형 데이터의 형변환 or 기본자료형 테이터의 형변환

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