#include "EmployeeHandler.h"
#include <iostream>

EmployeeHandler::EmployeeHandler() : empNum(0) 
{
	for (int i = 0; i < 50; i++)
	{
		empList[i] = nullptr;
	}
}
void EmployeeHandler::AddEmployee(Employee* emp)
{
	empList[empNum++] = emp;
}

void EmployeeHandler::ShowAllSalaryInfo() const
{

	for (int i = 0; i < empNum; i++)
		empList[i]->ShowSalaryInfo();
}

void EmployeeHandler::ShowTotalSalary() const
{
	int sum = 0;

	for (int i = 0; i < empNum; i++)
		sum += empList[i]->GetPay();

	cout << "salary sum: " << sum << endl;
}

EmployeeHandler::~EmployeeHandler()
{
	for (int i = 0; i < empNum; i++)
		delete empList[i];
}
