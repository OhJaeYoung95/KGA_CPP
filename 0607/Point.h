#pragma once
#include <iostream>
#include <cstdio>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0);
	void ShowPosition() const;

	friend ostream& operator << (ostream& os, const Point& pos);
	friend istream& operator >> (istream& is, Point& pos);

};

ostream& operator << (ostream& os, const Point& pos);
istream& operator >> (istream& is, Point& pos);
