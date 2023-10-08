/*
 * Ŭ���� �̸�: AccountHandler
 * Ŭ���� ����: ��Ʈ��(Control) Ŭ����
 */

#ifndef __CLASS_ACCOUNT_HANDLER_H__
#define __CLASS_ACCOUNT_HANDLER_H__

#include "Account.h"

class CAccountHandler
{
private:
	CAccount* accArr[100];
	int accNum;
protected:
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
public:
	CAccountHandler(void);
	~CAccountHandler(void);

	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;
};

#endif __CLASS_ACCOUNT_HANDLER_H__