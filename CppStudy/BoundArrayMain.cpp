#include "Point.h"
#include "ArrayTemplate.h"

int main(void) {
	BoundCheckArray<int> iarr(5);
	for (int i = 0; i < 5; i++)
		iarr[i] = i + 1;
	for (int i = 0; i < 5; i++)
		cout << iarr[i] << endl;
	cout << endl;

	BoundCheckArray<Point> oarr(3);
	oarr[0] =Point(3, 4);
	oarr[1] =Point(5, 6);
	oarr[2] =Point(7, 8);
	for (int i = 0; i < oarr.GetArrLen(); i++)
		cout << oarr[i];
	cout << endl;

	BoundCheckArray<Point*> parr(3);
	parr[0] = new Point(3, 4);
	parr[1] = new Point(5, 6);
	parr[2] = new Point(7, 8);
	for (int i = 0; i < parr.GetArrLen(); i++)
		cout << parr[i];

	delete parr[0];
	delete parr[1];
	delete parr[2];
	return 0;
}
