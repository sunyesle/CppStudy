#include <iostream>	
using namespace std;

class Rectangle {
private:
	int a,b;
public:
	Rectangle(int a, int b)
		: a(a), b(b) {}
	void ShowAreaInfo() const {
		cout << "¸éÀû: " << a * b << endl;
	}
};

class Square : public Rectangle {
public:
	Square(int a)
		: Rectangle(a,a) {}
};

int main(void) {
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}