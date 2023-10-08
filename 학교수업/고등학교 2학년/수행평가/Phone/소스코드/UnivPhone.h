#ifndef __UNIV_PHONE_H__
#define __UNIV_PHONE_H__

#include "PhoneCommon.h"
#include "PhoneInfo.h"

// 대학생 데이터 클래스, PhoneInfo클래스를 상속
class CUnivPhone : public CPhoneInfo
{
private:
	char* m_Major;
	int m_Grade;
public:
	CUnivPhone(char* _Name, char* _Number, char* _Major, int _Grade)
		: CPhoneInfo(_Name, _Number), m_Grade(_Grade)
	{
		m_Major = new char[strlen(_Major) + 1];
		strcpy(m_Major, _Major);
	}

	~CUnivPhone(void)
	{
		delete[] m_Major;
	}

	virtual void ShowInfo(void) const
	{
		cout << "이    름: " << CPhoneInfo::m_Name << endl;
		cout << "전화번호: " << CPhoneInfo::m_Number << endl;
		cout << "전    공: " << m_Major << endl;
		cout << "학    년: " << m_Grade << endl;
	}
};

#endif __UNIV_PHONE_H__