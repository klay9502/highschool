#include "BankingCommonDelc.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"


CAccountHandler::CAccountHandler(void) :accNum(0)
{
	// empty...
}

CAccountHandler::~CAccountHandler(void)
{
	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	}
}

void CAccountHandler::ShowMenu(void) const
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void CAccountHandler::MakeAccount(void)
{
	int sel;

	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ���" << endl;
	cout << "2.�ſ�ŷڰ���" << endl;
	cout << "����: "; cin >> sel;

	if (sel == NORMAL)
	{
		MakeNormalAccount();
	}
	else
	{
		MakeCreditAccount();
	}
}

void CAccountHandler::MakeNormalAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��  ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "������: "; cin >> interRate;
	cout << endl;

	accArr[accNum++] = new CNormalAccount(id, balance, name, interRate);
}

void CAccountHandler::MakeCreditAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��  ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "������: "; cin >> interRate;
	cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> creditLevel;
	cout << endl;

	switch (creditLevel)
	{
	case 1:
		accArr[accNum++] = new CHighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new CHighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new CHighCreditAccount(id, balance, name, interRate, LEVEL_C);
		break;
	}
}

void CAccountHandler::DepositMoney(void)
{
	int money;
	int id;
	cout << "[��    ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}

	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void CAccountHandler::WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[��    ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}

			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}

	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void CAccountHandler::ShowAllAccInfo(void) const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}