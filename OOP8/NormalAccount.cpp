#include <iostream>
#include "NormalAccount.h"

using namespace std;

NormalAccount::NormalAccount() :Account(nullptr, 0, 0), ratio(0){}

NormalAccount::NormalAccount(const char* name, int id, int balance, int ratio) :Account(name, id, balance), ratio(ratio)
{
}
NormalAccount::~NormalAccount()
{
	cout << "NormalAccount ÇØÁ¦" << endl;
}
//
//void NormalAccount::SetName(const char*)
//{
//}
//
//int NormalAccount::GetId() const
//{
//	return 0;
//}

bool NormalAccount::Deposit(int money)
{
	double interest = ratio * 0.01 * money;
	//9 0.09
	balance += money + interest;
	return true;
}

//bool NormalAccount::Withdraw(int money)
//{
//	return false;
//}
//
//void NormalAccount::Print() const
//{
//	Account::Print();
//	cout << 
//}