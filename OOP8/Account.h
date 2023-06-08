#pragma once
class Account
{
private:
	char* name;
	int id;

	void Release();

protected:
	int balance;
public:
	Account();
	Account(const char* name, int id, int balance);
	Account(const Account& ref);
	virtual ~Account();


	void SetName(const char*);
	int GetId() const;

	virtual bool Deposit(int money);
	bool Withdraw(int money);

	void Print() const;
};

