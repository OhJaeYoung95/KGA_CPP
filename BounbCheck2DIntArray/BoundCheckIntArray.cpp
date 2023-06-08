#include "BoundCheckIntArray.h"

BoundCheckIntArray::BoundCheckIntArray(const BoundCheckIntArray& _arr) : arr(nullptr), arrlen(0)
{
	if (arr != nullptr)
		delete[] arr;
	if (_arr.arr != nullptr)
	{
		arr = new int[_arr.arrlen];
	}
	else
	{
		arr = nullptr;
	}
	arrlen = _arr.arrlen;
}

BoundCheckIntArray& BoundCheckIntArray::operator=(const BoundCheckIntArray& _arr)
{
	if (arr != nullptr)
		delete[] arr;
	if (_arr.arr != nullptr)
	{
		arr = new int[_arr.arrlen];
	}
	else
	{
		arr = nullptr;
	}
	arrlen = _arr.arrlen;
	return *this;
}

BoundCheckIntArray::BoundCheckIntArray(int len) : arrlen(len)
{
	arr = new int[len];
}

int& BoundCheckIntArray::operator[](int idx) 
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}

	return arr[idx];
}

int BoundCheckIntArray::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}

	return arr[idx];
}

int BoundCheckIntArray::GetArrLen() const
{
	return arrlen;
}

BoundCheckIntArray::~BoundCheckIntArray()
{
	if(arr != nullptr)
		delete[] arr;
}
