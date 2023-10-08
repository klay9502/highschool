/*
 * Ŭ���� �̸�: Account
 * Ŭ���� ����: Entity Ŭ����
 */

#ifndef __CLASS_ACCOUNT_H__
#define __CLASS_ACCOUNT_H__

class CAccount
{
private:
	int accID;
	int balance;
	char* cusName;
public:
	CAccount(int _ID, int _money, char* _name);
	CAccount(const CAccount& ref);
	~CAccount(void);

	int GetAccID(void) const;
	virtual void Deposit(int _money);
	int Withdraw(int _money);
	void ShowAccInfo(void) const;
};

#endif __CLASS_ACCOUNT_H__