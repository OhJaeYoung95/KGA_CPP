#pragma once
#include "BoundCheckIntArray.h"

class BoundCheck2DIntArray
{
private:
	BoundCheckIntArray** arr2d;
	int rowLen;
	int colLen;
public:
	BoundCheck2DIntArray(int row, int col);
	~BoundCheck2DIntArray();

	BoundCheckIntArray& operator[] (int index);
};