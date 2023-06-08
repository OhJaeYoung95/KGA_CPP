#pragma once
#include "Employee.h"
#include <iostream>

using namespace std;

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler();
	void AddEmployee(Employee* emp);

	void ShowAllSalaryInfo() const;
	void ShowTotalSalary() const;
	~EmployeeHandler();
};