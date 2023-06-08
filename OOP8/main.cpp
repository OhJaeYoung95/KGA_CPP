#include <iostream>
#include "Account.h"
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

using namespace std;
enum class COMMANDS
{
	NONE,
	CREATE,
	DEPOSIT,
	WITHDRAW,
	PRINT,
	EXIT
};

int main()
{
	AccountHandler system1;
	int input = 0;
	COMMANDS cmd = COMMANDS::EXIT;
	int select = 0;
	int id = 0;
	char str[128];
	int money = 0;	
	int ratio = 0;

	CreditRank creditRank = CreditRank::NONE;
	int rank = 0;

	do	
	{
		system1.PrintMenu();
		cout << "선택: ";
		cin >> input;
		cout << "-------------------------" << endl<<endl;
		cmd = (COMMANDS)input;

		switch ((COMMANDS)cmd)
		{
		case COMMANDS::CREATE:
			cout << "[계좌종류선택]" << endl;
			cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
			cout << "선택: ";
			cin >> select;

			if (select == 1)
				cout << "[보통예금계좌 계설]" << endl;
			else if (select == 2)
				cout << "[신용예금계좌 개설]" << endl;
			cout << "계좌ID: ";
			cin >> id;
			cout << "이름: ";
			cin >> str;
			cout << "입금액: ";
			cin >> money;
			cout << "이자율: ";
			cin >> ratio;
			if (select == 2)
			{
				cout << "신용등급(1toA, 2toB, 3toC): ";
				cin >> rank;
				creditRank = (CreditRank)rank;
			}
			if(select == 1)
				system1.Create(str, id, money, ratio);
			else if(select == 2)
				system1.Create(str, id, money, ratio, creditRank);
			break;
		case COMMANDS::DEPOSIT:
			cout << "[입 금]" << endl;
			cout << "계좌번호: ";
			cin >> id;
			cout << "입금액: ";
			cin >> money;

			if (system1.Deposit(id, money))
			{
				cout << "입금 완료" << endl;
			}
			else
				cout << "입금 실패" << endl;
			break;
		case COMMANDS::WITHDRAW:
			cout << "[출 금]" << endl;
			cout << "계좌번호: ";
			cin >> id;
			cout << "출금액: ";
			cin >> money;
			if (system1.Withdraw(id, money))
				cout << "출금 완료" << endl;
			else
				cout << "출금 실패" << endl;
			break;
		case COMMANDS::PRINT:
			system1.PrintAll();
			break;
		case COMMANDS::EXIT:
			break;
		default:
			break;
		}
	} while (cmd != COMMANDS::EXIT);


	return 0;
}