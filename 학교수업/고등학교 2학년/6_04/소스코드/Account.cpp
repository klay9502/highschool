#include "BankingCommonDelc.h"
#include "Account.h"


CAccount::CAccount(int _ID, int _money, char* _name)
	: accID(_ID), balance(_money)
{
	cusName = new char[strlen(_name) + 1];
	strcpy(cusName, _name);
}

CAccount::CAccount(const CAccount &ref)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}

CAccount::~CAccount(void)
{
	delete[]cusName;
}

int CAccount::GetAccID(void) const { return accID; }

void CAccount::Deposit(int _money)
{
	balance += _money;
}

int CAccount::Withdraw(int _money)
{
	if (balance < _money)
	{
		return 0;
	}

	balance -= _money;

	return _money;
}

void CAccount::ShowAccInfo(void) const
{
	cout << "����ID: " << accID << endl;
	cout << "��  ��: " << cusName << endl;
	cout << "��  ��: " << balance << endl;
}