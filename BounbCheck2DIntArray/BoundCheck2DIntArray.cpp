#include "BoundCheck2DIntArray.h"

BoundCheck2DIntArray::BoundCheck2DIntArray(int row, int col) 
	: rowLen(row), colLen(col)
{
	arr2d = new BoundCheckIntArray* [rowLen];
	for (int i = 0; i < rowLen; i++)
	{
		arr2d[i] = new BoundCheckIntArray(colLen);
	}
}

BoundCheckIntArray& BoundCheck2DIntArray::operator[](int index)
{
	return *arr2d[index];
}

BoundCheck2DIntArray::~BoundCheck2DIntArray()
{
		for (int i = 0; i < rowLen; i++)
		{
			delete arr2d[i];
		}
		delete[] arr2d;
}