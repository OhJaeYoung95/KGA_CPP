#include "AccountHandler.h"
#include "HighCreditAccount.h"
#include <iostream>
using namespace std;

AccountHandler::AccountHandler() : accounts(), count(0)
{
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < count; i++)
	{
		delete accounts[i];
	}
}

void AccountHandler::PrintMenu()
{
	cout << endl;
	cout << "-------------------------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

bool AccountHandler::Create(char* str, int id, int money, int ratio, CreditRank creditRank)
{
	accounts[count++] = new HighCreditAccount(str, id, money, ratio, creditRank);
	return true;
}

bool AccountHandler::Create(char* str, int id, int money, int ratio)
{
	accounts[count++] = new NormalAccount(str, id, money, ratio);
	return true;
}

int AccountHandler::Find(int id) const
{
	for (int i = 0; i < count; i++)
	{
		if (accounts[i]->GetId() == id)
		{
			return i;
		}
	}
	return -1;
}

bool AccountHandler::Deposit(int id, int money)
{
	int find = Find(id);
	if (find == -1)
	{
		return false;
	}

	return 	accounts[find]->Deposit(money);
}

bool AccountHandler::Withdraw(int id, int money)
{
	int find = Find(id);
	if (find == -1)
	{
		return false;
	}
	return 	accounts[find]->Withdraw(money);
}

void AccountHandler::PrintAll() const
{
	for (int i = 0; i < count; i++)
	{
		accounts[i]->Print();
	}
}
