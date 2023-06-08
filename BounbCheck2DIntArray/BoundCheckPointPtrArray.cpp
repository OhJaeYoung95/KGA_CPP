#include "BoundCheckPointPtrArray.h"
#include "iostream"

using namespace std;

BoundCheckPointPtrArray::BoundCheckPointPtrArray(const BoundCheckPointPtrArray& _arr)
{
	if (arr != nullptr)
		delete[] arr;
	if (_arr.arr != nullptr)
	{
		arr = new POINT_PTR[_arr.arrlen];
	}
	else
	{
		arr = nullptr;
	}
	arrlen = _arr.arrlen;
}

BoundCheckPointPtrArray& BoundCheckPointPtrArray::operator=(const BoundCheckPointPtrArray& _arr)
{
	if (arr != nullptr)
		delete[] arr;
	if (_arr.arr != nullptr)
	{
		arr = new POINT_PTR[_arr.arrlen];
	}
	else
	{
		arr = nullptr;
	}
	arrlen = _arr.arrlen;
	return *this;
}

BoundCheckPointPtrArray::BoundCheckPointPtrArray(int len) : arrlen(len)
{
	arr = new POINT_PTR[len];
}

POINT_PTR& BoundCheckPointPtrArray::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

POINT_PTR BoundCheckPointPtrArray::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

int BoundCheckPointPtrArray::GetArrLen() const
{
	return arrlen;
}

BoundCheckPointPtrArray::~BoundCheckPointPtrArray()
{
	delete[] arr;
}

ostream& operator<<(ostream& os, const POINT_PTR arr)
{
	os << *(arr) ;
	return os;
}
