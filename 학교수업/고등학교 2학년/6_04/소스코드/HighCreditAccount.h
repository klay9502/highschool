/*
 * 클래스 이름: HighCreditAccount
 * 클래스 유형: Entity 클래스
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
		CNormalAccount::Deposit(_money);		// 원금과 이자추가
		CAccount::Deposit(_money*(specialRate / 100.0));		// 특별이자추가	
	}
};

#endif __HIGHCREDIT_ACOUNT_H__