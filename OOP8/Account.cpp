#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"
#include "string"
#include <iostream>
using namespace std;

Account::Account() : name(nullptr), id(0), balance(0)
{
}

Account::Account(const char* name, int id, int balance) : name(nullptr), id(id), balance(balance)
{
	SetName(name);
}

Account::Account(const Account& ref) : name(nullptr), id(ref.id), balance(ref.balance)
{
	SetName(name);
}

Account::~Account()
{
	Release();
	cout << "Account ÇØÁ¦" << endl;
}

void Account::Release()
{
	if (this->name != nullptr)
	{
		delete[] this->name;
		this->name = nullptr;
	}
}

void Account::SetName(const char* name)
{
	Release();

	int length = strlen(name) + 1;
	this->name = new char[length];
	strcpy(this->name, name);
}

int Account::GetId() const
{
	return id;
}

bool Account::Deposit(int money)
{
	balance += money;
	return true;
}

bool Account::Withdraw(int money)
{
	balance -= money;
	return true;
}

void Account::Print() const
{
	cout << "-------------------------" << endl;
	cout << "ÀÌ¸§: " << name << endl;
	cout << "°èÁÂ¹øÈ£: " << id << endl;
	cout << "ÀÜ¾×: " << balance << endl;
	cout << "-------------------------" << endl;
}

