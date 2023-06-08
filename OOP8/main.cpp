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
		cout << "����: ";
		cin >> input;
		cout << "-------------------------" << endl<<endl;
		cmd = (COMMANDS)input;

		switch ((COMMANDS)cmd)
		{
		case COMMANDS::CREATE:
			cout << "[������������]" << endl;
			cout << "1. ���뿹�ݰ��� 2. �ſ�ŷڰ���" << endl;
			cout << "����: ";
			cin >> select;

			if (select == 1)
				cout << "[���뿹�ݰ��� �輳]" << endl;
			else if (select == 2)
				cout << "[�ſ뿹�ݰ��� ����]" << endl;
			cout << "����ID: ";
			cin >> id;
			cout << "�̸�: ";
			cin >> str;
			cout << "�Աݾ�: ";
			cin >> money;
			cout << "������: ";
			cin >> ratio;
			if (select == 2)
			{
				cout << "�ſ���(1toA, 2toB, 3toC): ";
				cin >> rank;
				creditRank = (CreditRank)rank;
			}
			if(select == 1)
				system1.Create(str, id, money, ratio);
			else if(select == 2)
				system1.Create(str, id, money, ratio, creditRank);
			break;
		case COMMANDS::DEPOSIT:
			cout << "[�� ��]" << endl;
			cout << "���¹�ȣ: ";
			cin >> id;
			cout << "�Աݾ�: ";
			cin >> money;

			if (system1.Deposit(id, money))
			{
				cout << "�Ա� �Ϸ�" << endl;
			}
			else
				cout << "�Ա� ����" << endl;
			break;
		case COMMANDS::WITHDRAW:
			cout << "[�� ��]" << endl;
			cout << "���¹�ȣ: ";
			cin >> id;
			cout << "��ݾ�: ";
			cin >> money;
			if (system1.Withdraw(id, money))
				cout << "��� �Ϸ�" << endl;
			else
				cout << "��� ����" << endl;
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