#ifndef __ACCOUNT_ARRAY__
#define __ACCOUNT_ARRAY__

#include "Account.h"
typedef Account * ACCOUNT_PTR;

class BoundCheckAccountPtrArray
{
private:
	ACCOUNT_PTR * arr;
	int arrlen;

	BoundCheckAccountPtrArray operator=(const BoundCheckAccountPtrArray& arr) {}
	BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr) {}
public:
	BoundCheckAccountPtrArray(int arrlen = 100);
	ACCOUNT_PTR& operator[](int idx);
	ACCOUNT_PTR operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckAccountPtrArray();
};

#endif // !__ACCOUNT_ARRAY__
