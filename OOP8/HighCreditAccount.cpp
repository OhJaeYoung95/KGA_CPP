#include <iostream>
#include "HighCreditAccount.h"

using namespace std;

HighCreditAccount::HighCreditAccount() : NormalAccount(nullptr, 0, 0,0), rank(CreditRank::NONE){}
HighCreditAccount::HighCreditAccount(const char* name, int id, int balance, int ratio, CreditRank creditRank) : NormalAccount(name, id, balance, ratio), rank(creditRank)
{

}
HighCreditAccount::~HighCreditAccount()
{
	cout << "HighCreditAccount ÇØÁ¦" << endl;

}
//
//void HighCreditAccount::SetName(const char*)
//{
//}
//
//int HighCreditAccount::GetId() const
//{
//	return 0;
//}

bool HighCreditAccount::Deposit(int money)
{
	double interestNormal = ratio * 0.01 * money;
	double interestHigh = 0;
	switch (rank)
	{
	case CreditRank::CREDIT_A:
		interestHigh = interestNormal + 0.07 * money;
		break;
	case CreditRank::CREDIT_B:
		interestHigh = interestNormal + 0.04 * money;
		break;
	case CreditRank::CREDIT_C:
		interestHigh = interestNormal + 0.02 * money;
		break;
	}
	balance += money + interestHigh;
	return true;
}

//bool HighCreditAccount::Withdraw(int money)
//{
//	return false;
//}
//
//void HighCreditAccount::Print() const
//{
//}
