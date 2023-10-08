/*
 * 클래스 이름: AccountHandler
 * 클래스 유형: 컨트롤(Control) 클래스
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