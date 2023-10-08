/*
 * Ŭ���� �̸�: HighCreditAccount
 * Ŭ���� ����: Entity Ŭ����
 */

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class CHighCreditAccount : public CNormalAccount
{
private:
	int specialRate;
public:
	CHighCreditAccount(int _ID, int _money, char* _name, int _rate, int _special)
		: CNormalAccount(_ID, _money, _name, _rate), specialRate(_special)
	{
		// empty...
	}

	virtual void Deposit(int _money)
	{
		CNormalAccount::Deposit(_money);		// ���ݰ� �����߰�
		CAccount::Deposit(_money*(specialRate / 100.0));		// Ư�������߰�	
	}
};

#endif __HIGHCREDIT_ACOUNT_H__