#pragma once
#include <iostream>
#include "PermanentWorker.h"

using namespace std;

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;    // 월 판매실적
	double bonusRatio;    // 상여금 비율 
public:
	SalesWorker(const char* name, int money, double ratio);
	void AddSalesResult(int value);
	int GetPay() const override;
	void ShowSalaryInfo() const override;
};

