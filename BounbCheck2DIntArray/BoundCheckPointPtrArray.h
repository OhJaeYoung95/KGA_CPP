#pragma once
#include <iostream>
#include "Point.h"

using namespace std;

//class Point;

typedef Point* POINT_PTR;

class BoundCheckPointPtrArray
{
private:
	POINT_PTR* arr;
	int arrlen;

	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& _arr);
	BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr);

public:
	BoundCheckPointPtrArray(int len);
	POINT_PTR& operator[](int idx);

	POINT_PTR operator[](int idx) const;
	int GetArrLen() const;

	friend ostream& operator<<(ostream& os, const POINT_PTR pos);

	~BoundCheckPointPtrArray();
};

ostream& operator<<(ostream& os, const POINT_PTR pos);