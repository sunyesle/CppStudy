#include "BankingCommonDecl.h"
#include "AccountArray.h"

BoundCheckArray::BoundCheckArray(int arrlen)
	:arrlen(arrlen)
{
	arr = new Account*[arrlen];
}

ACCOUNT_PTR & BoundCheckArray::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen) {
		cout << "범위 초과" << endl;
		exit(1);
	}
	else {
		return arr[idx++];
	}
}

ACCOUNT_PTR BoundCheckArray::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen) {
		cout << "범위 초과" << endl;
		exit(1);
	}
	else {
		return arr[idx++];
	}
}

int BoundCheckArray::GetArrLen() const
{
	return arrlen;
}

BoundCheckArray::~BoundCheckArray()
{
	delete[] arr;
}
