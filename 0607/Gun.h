#pragma once
#include <iostream>
using namespace std;
class Gun
{
private:
	int bullet;
public:
	Gun();
	Gun(int bnum);
	void Shot();
	int GetBullet();
};