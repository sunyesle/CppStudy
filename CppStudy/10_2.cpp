#include <iostream> 
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}
	void ShowPosition() const {
		cout << '[' << xpos << ',' << ypos << ']' << endl;
	}
	Point operator-() {
		Point pos(-xpos, -ypos);
		return pos;
	}
	friend Point operator~(Point &ref);
};

Point operator~(Point & ref)
{
	Point pos(ref.ypos, ref.xpos);
	return pos;
}

int main(void) {
	Point pos1(10, -5);
	pos1.ShowPosition();
	Point pos2 = -pos1;
	pos2.ShowPosition();
	(~pos2).ShowPosition();
	pos2.ShowPosition();
	return 0;
}
