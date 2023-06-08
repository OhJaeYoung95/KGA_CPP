#pragma once
#include <iostream>
#include "Employee.h"

using namespace std;

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	PermanentWorker(const char* name, int money);
	int GetPay() const override;
	void ShowSalaryInfo() const override;
};