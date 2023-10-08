#ifndef __NORMAL_PHONE_H__
#define __NORMAL_PHONE_H__

#include "PhoneInfo.h"

// 일반 데이터 클래스, PhoneInfo클래스를 상속
class CNormalPhone : public CPhoneInfo
{
public:
	CNormalPhone(char* _Name, char* _Number)
		: CPhoneInfo(_Name, _Number){}
	~CNormalPhone(void);

	virtual void ShowInfo(void) const
	{
		cout << "이    름: " << CPhoneInfo::m_Name << endl;
		cout << "전화번호: " << CPhoneInfo::m_Number << endl;
	}
};

#endif __NORMAL_PHONE_H__