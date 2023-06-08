#include <iostream>
#include "TemporaryWorker.h"

TemporaryWorker::TemporaryWorker(const char* name, int pay)
	: Employee(name), workTime(0), payPerHour(pay)
{  }


void TemporaryWorker::AddWorkTime(int time)
{
	workTime += time;
}
int TemporaryWorker::GetPay() const
{
	return workTime * payPerHour;
}
void TemporaryWorker::ShowSalaryInfo() const
{
	ShowYourName();
	cout << "salary: " << GetPay() << endl << endl;
}
