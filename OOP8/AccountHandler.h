#pragma once
#include "Account.h"
#include "HighCreditAccount.h"
#define ACCOUNT_SIZE 128


class AccountHandler
{
private:
	NormalAccount* accounts[ACCOUNT_SIZE];
	int count;
public:
	AccountHandler();
	~AccountHandler();

	void PrintMenu();
	bool Create(char* str, int id, int money, int ratio,
		CreditRank creditRank);
	bool Create(char* str, int id, int money, int ratio);
	int Find(int id) const;	// false: -1
	bool Deposit(int id, int money);
	bool Withdraw(int id, int money);
	void PrintAll() const;
};