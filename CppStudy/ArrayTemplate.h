#ifndef __ARRYA_TEMPLATE__
#define __ARRYA_TEMPLATE__

#include <iostream> 
#include <cstring>
using namespace std;

template <typename T>
class BoundCheckArray
{
private:
	T * arr;
	int arrlen;

	BoundCheckArray(const BoundCheckArray& arr) {}
	BoundCheckArray& operator=(const BoundCheckArray& arr) {}

public:
	BoundCheckArray(int len) : arrlen(len)
	{
		arr = new T[len];
	}
	T& operator[] (int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	T operator[] (int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }
	BoundCheckArray() { delete[] arr; }
};

#endif