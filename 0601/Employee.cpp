#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee(const char* name)
{
	strcpy(this->name, name);
}

void Employee::ShowYourName() const
{
	cout << "name: " << name << endl;
}

//int Employee::GetPay() const {}
//void Employee::ShowSalaryInfo() const {}