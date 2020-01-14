#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x, int y) : xpos(x), ypos(y) {}
	void ShowPosition() const {
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}
	friend Point operator+=(const Point &pos2);
	friend Point operator-=(const Point &pos2);
};


int main(void) {
	Point pos1(10, 20);
	Point pos2(1, 2);

	pos1.ShowPosition();
	pos2.ShowPosition();

	pos1 += pos2;
	pos1.ShowPosition();

	pos1 -= pos2;
	pos1.ShowPosition();

	return 0;
}

Point operator+=(const Point & pos2)
{
	pos1.xpos += pos2.xpos;
	pos1.ypos += pos2.ypos;
	return pos1;
}

Point operator-=(const Point & pos2)
{
	pos1.xpos -= pos2.xpos;
	pos1.ypos -= pos2.ypos;
	return pos1;
}

