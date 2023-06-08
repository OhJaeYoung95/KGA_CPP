#include <iostream>
#include "ForeignSaleWorker.h"

ForeignSalesWorker::ForeignSalesWorker(const char* name, int money, double ratio, RISK_LEVEL risk) 
	: SalesWorker(name, money, ratio) , risk(risk)
{

}

//ForeignSalesWorker::~ForeignSalesWorker()
//{
//
//}

//void ForeignSalesWorker::AddSalesResult(int value)
//{
//
//}

int ForeignSalesWorker::GetPay() const
{
	int riskPay = 0;
	switch (risk)
	{
	case RISK_LEVEL::RISK_A:
		riskPay = SalesWorker::GetPay() * 0.3;
		break;
	case RISK_LEVEL::RISK_B:
		riskPay = SalesWorker::GetPay() * 0.2;
		break;
	case RISK_LEVEL::RISK_C:
		riskPay = SalesWorker::GetPay() * 0.1;
		break;
	default:
		break;
	}
	return SalesWorker::GetPay() + riskPay;
}

void ForeignSalesWorker::ShowSalaryInfo() const
{
	ShowYourName();
	cout << "salary: " << SalesWorker::GetPay() << endl;
	cout << "risk pay: " << ForeignSalesWorker::GetPay() - SalesWorker::GetPay() << endl;
	cout << "sum: " << ForeignSalesWorker::GetPay() << endl << endl;
}
