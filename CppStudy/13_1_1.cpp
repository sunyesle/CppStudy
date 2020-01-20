#include <iostream> 
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}
	void ShowPosition()	const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

template <class T>
void SwapData(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	Point a(1, 2);
	Point b(3, 4);

	a.ShowPosition();
	b.ShowPosition();

	cout << endl;
	SwapData(a, b);

	a.ShowPosition();
	b.ShowPosition();
	return 0;
}