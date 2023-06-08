#include <iostream>
#include <cstdlib>
#include "BoundCheckPointPtrArray.h"
#include "Point.h"
#include "BoundCheck2DIntArray.h"
using namespace std;

void Practice1()
{
	BoundCheckPointPtrArray arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << arr[i];//cout << *(arr[i]);
	delete arr[0];
	delete arr[1];
	delete arr[2];
}

void Practice2()
{
	BoundCheck2DIntArray arr2d(3, 4);

	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 4; m++)
		{
			arr2d[n][m] = n + m;
		}
	}
	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 4; m++)
		{
			cout << arr2d[n][m] << " ";
		}
		cout << endl;
	}
}

int main()
{
	Practice2();

	return 0;
}