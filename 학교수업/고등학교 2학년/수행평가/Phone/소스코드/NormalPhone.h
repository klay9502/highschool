#ifndef __NORMAL_PHONE_H__
#define __NORMAL_PHONE_H__

#include "PhoneInfo.h"

// �Ϲ� ������ Ŭ����, PhoneInfoŬ������ ���
class CNormalPhone : public CPhoneInfo
{
public:
	CNormalPhone(char* _Name, char* _Number)
		: CPhoneInfo(_Name, _Number){}
	~CNormalPhone(void);

	virtual void ShowInfo(void) const
	{
		cout << "��    ��: " << CPhoneInfo::m_Name << endl;
		cout << "��ȭ��ȣ: " << CPhoneInfo::m_Number << endl;
	}
};

#endif __NORMAL_PHONE_H__