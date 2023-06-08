#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;

	BoundCheckIntArray(const BoundCheckIntArray& _arr);
	BoundCheckIntArray& operator=(const BoundCheckIntArray& _arr);

public:
	BoundCheckIntArray(int len);
	int& operator[](int idx);

	int operator[](int idx) const;

	int GetArrLen() const;
	~BoundCheckIntArray();
};