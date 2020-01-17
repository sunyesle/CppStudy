#include "BankingCommonDecl.h"
#include "AccountArray.h"

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int arrlen)
	:arrlen(arrlen)
{
	arr = new Account*[arrlen];
}

ACCOUNT_PTR & BoundCheckAccountPtrArray::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen) {
		cout << "범위 초과" << endl;
		exit(1);
	}
	else {
		return arr[idx++];
	}
}

ACCOUNT_PTR BoundCheckAccountPtrArray::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen) {
		cout << "범위 초과" << endl;
		exit(1);
	}
	else {
		return arr[idx++];
	}
}

int BoundCheckAccountPtrArray::GetArrLen() const
{
	return arrlen;
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray()
{
	delete[] arr;
}
