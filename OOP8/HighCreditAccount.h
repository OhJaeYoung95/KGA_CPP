#pragma once
#include "NormalAccount.h"

enum class CreditRank
{
	NONE,
	CREDIT_A,
	CREDIT_B,
	CREDIT_C
};

class HighCreditAccount : public NormalAccount
{
private:
	CreditRank rank;
public:
	HighCreditAccount();
	HighCreditAccount(const char* name, int id, int balance, int ratio, CreditRank creditRank);
	~HighCreditAccount() override;

	//void SetName(const char*);
	//int GetId() const;

	bool Deposit(int money) override;
	//bool Withdraw(int money);

	//void Print() const override;

};

