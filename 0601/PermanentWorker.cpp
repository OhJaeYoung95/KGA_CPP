#include "PermanentWorker.h"
#include <iostream>
using namespace std;

PermanentWorker::PermanentWorker(const char* name, int money) : Employee(name), salary(money) {}

int PermanentWorker::GetPay() const
{
	return salary;
}

void PermanentWorker::ShowSalaryInfo() const
{
	ShowYourName();
	cout << "salary: " << GetPay() << endl << endl;
}