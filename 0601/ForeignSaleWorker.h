#pragma once
#include "SalesWorker.h"
enum class RISK_LEVEL
{
	RISK_A,
	RISK_B,
	RISK_C
};

class ForeignSalesWorker : public SalesWorker
{
private:
	RISK_LEVEL risk;
public:
	ForeignSalesWorker(const char* name, int money, double ratio, RISK_LEVEL risk);
	//~ForeignSalesWorker();
	//void AddSalesResult(int value);
	int GetPay() const override;
	void ShowSalaryInfo() const override;

};

