#ifndef __ACCOUNT_ARRAY__
#define __ACCOUNT_ARRAY__

#include "Account.h"

template <typename T>
class BoundCheckArray
{
private:
	T * arr;
	int arrlen;

	BoundCheckArray operator=(const BoundCheckArray& arr) {}
	BoundCheckArray(const BoundCheckArray& arr) {}
public:
	BoundCheckArray(int arrlen = 100);
	T& operator[](int idx);
	T operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int arrlen)
	:arrlen(arrlen)
{
	arr = new Account*[arrlen];
}

template <typename T>
T & BoundCheckArray<T>::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen) {
		cout << "범위 초과" << endl;
		exit(1);
	}
	else {
		return arr[idx++];
	}
}

template <typename T>
T BoundCheckArray<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen) {
		cout << "범위 초과" << endl;
		exit(1);
	}
	else {
		return arr[idx++];
	}
}

template <typename T>
int BoundCheckArray<T>::GetArrLen() const
{
	return arrlen;
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[] arr;
}


#endif // !__ACCOUNT_ARRAY__
