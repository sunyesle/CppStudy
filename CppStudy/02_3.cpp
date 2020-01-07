#include <iostream>
using namespace std;

typedef struct __Point {
	int xpos;
	int ypos;
}Point;

Point& PntAdder(const Point & p1, const Point & p2) {
	Point* result = new Point{ p1.xpos + p2.xpos ,p1.ypos + p2.ypos };
	return *result;
}

void main(void) {
	Point* a = new Point { 1, 12 };
	Point* b = new Point { 20, 5 };
	Point* result = &PntAdder(*a, *b);

	cout << result->xpos << " " << result->ypos << endl;
	delete a;
	delete b;
	delete result;
}