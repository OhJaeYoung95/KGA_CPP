#pragma once
#include <iostream>
#include "PermanentWorker.h"

using namespace std;

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;    // �� �ǸŽ���
	double bonusRatio;    // �󿩱� ���� 
public:
	SalesWorker(const char* name, int money, double ratio);
	void AddSalesResult(int value);
	int GetPay() const override;
	void ShowSalaryInfo() const override;
};

