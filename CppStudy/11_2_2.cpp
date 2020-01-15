#include <iostream>
using namespace std;

class BoundCheck2DIntArray
{
private:
	int * arr;
	int xlen,ylen;
	int temp;
public:
	BoundCheck2DIntArray(int x, int y) 
		: xlen(x), ylen(y),temp(-1)
	{
		arr = new int[x*y +1];
	}
	int GetXLen() {
		return xlen;
	}
	int GetYLen() {
		return ylen;
	}
	BoundCheck2DIntArray& operator[](int i) {
		if (temp==-1) {
			if (i < 0 || i >= xlen) {
				temp = i*(ylen);
				return *this;
			}
			else {
				cout << "오류 x" << endl;
				exit(1);
			}
		}
		else {
			if (i < 0 || i >= ylen) {
				temp += i;
				return *this;
			}
			else {
				cout << "오류 y" << endl;
				exit(1);
			}
		}
	}
	BoundCheck2DIntArray& operator=(int i) {
		arr[temp] = i;
		temp = -1;
		return *this;
	}
	friend ostream& operator<<(ostream&, BoundCheck2DIntArray&);
};

ostream & operator<<(ostream & os, BoundCheck2DIntArray & bcia)
{
	os << bcia.arr[bcia.temp];
	bcia.temp = -1;
	return os;
}

int main(void) {
	BoundCheck2DIntArray arr(3, 4);
	for (int i = 0; i < arr.GetXLen(); i++)
	{
		for (int j = 0; j < arr.GetYLen(); j++)
		{
			arr[i][j] = i * arr.GetXLen() + j;
		}
	}
	for (int i = 0; i < arr.GetXLen(); i++)
	{
		for (int j = 0; j < arr.GetYLen(); j++)
		{
			cout << arr[i][j] << endl;
		}
	}
}
