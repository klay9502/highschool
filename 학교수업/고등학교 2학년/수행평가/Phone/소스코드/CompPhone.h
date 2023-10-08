#ifndef __COMP_PHONE_H__
#define __COMP_PHONE_H__

#include "PhoneCommon.h"
#include "PhoneInfo.h"

// 회사원 데이터 클래스, PhoneInfo클래스를 상속
class CCompPhone : public CPhoneInfo
{
private:
	char* m_Company;
public:
	CCompPhone(char* _Name, char* _Number, char* _Comp)
		: CPhoneInfo(_Name, _Number)
	{
		m_Company = new char[strlen(_Comp) + 1];
		strcpy(m_Company, _Comp);
	}

	~CCompPhone(void)
	{
		delete[] m_Company;
	}

	virtual void ShowInfo(void) const
	{
		cout << "이    름: " << CPhoneInfo::m_Name << endl;
		cout << "전화번호: " << CPhoneInfo::m_Number << endl;
		cout << "회    사: " << m_Company << endl;
	}
};

#endif __COMP_PHONE_H__