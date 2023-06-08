#pragma once
#include "Gun.h"
#include "iostream"
class Police
{
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff);
	Police(Police& ref);
	void PutHandcuff();
	void Shot();
	~Police();
	
	Police& operator=(const Police& ref);
};