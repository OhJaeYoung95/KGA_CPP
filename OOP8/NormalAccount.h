#pragma once
#include "Account.h"
class NormalAccount : public Account
{
protected:
	int ratio;

public:
	NormalAccount();
	NormalAccount(const char* name, int id, int balance, int ratio);
	~NormalAccount() override;
	//void SetName(const char*);
	//int GetId() const;

	bool Deposit(int money) override;
	//bool Withdraw(int money);

	//void Print() const override;

};

