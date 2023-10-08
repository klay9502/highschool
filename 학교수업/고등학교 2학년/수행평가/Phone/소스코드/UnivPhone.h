#ifndef __UNIV_PHONE_H__
#define __UNIV_PHONE_H__

#include "PhoneCommon.h"
#include "PhoneInfo.h"

// ���л� ������ Ŭ����, PhoneInfoŬ������ ���
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
		cout << "��    ��: " << CPhoneInfo::m_Name << endl;
		cout << "��ȭ��ȣ: " << CPhoneInfo::m_Number << endl;
		cout << "��    ��: " << m_Major << endl;
		cout << "��    ��: " << m_Grade << endl;
	}
};

#endif __UNIV_PHONE_H__