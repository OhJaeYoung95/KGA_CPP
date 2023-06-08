#pragma once
#include <iostream>
#include "Employee.h"

using namespace std;

class TemporaryWorker : public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char* name, int pay);
	void AddWorkTime(int time);
	int GetPay() const override;
	void ShowSalaryInfo() const override;
};
