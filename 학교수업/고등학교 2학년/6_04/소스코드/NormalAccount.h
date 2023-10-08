/*
 * Ŭ���� �̸�: NormalAccount
 * Ŭ���� ����: Entity Ŭ����
 */

#ifndef __CLASS_NORMAL_ACCOUNT
#define __CLASS_NORMAL_ACCOUNT

#include "Account.h"

class CNormalAccount : public CAccount
{
private:
	int interRate;	// ������ %����
public:
	CNormalAccount(int _ID, int _money, char* _name, int _rate)
		: CAccount(_ID, _money, _name), interRate(_rate)
	{
		// empty...
	}
	~CNormalAccount(void);

	virtual void Deposit(int _money)
	{
		CAccount::Deposit(_money);
		CAccount::Deposit(_money*(interRate / 100.0));
	}
};

#endif __CLASS_NORMAL_ACCOUNT