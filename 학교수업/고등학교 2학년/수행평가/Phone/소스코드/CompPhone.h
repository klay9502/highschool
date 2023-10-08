#ifndef __COMP_PHONE_H__
#define __COMP_PHONE_H__

#include "PhoneCommon.h"
#include "PhoneInfo.h"

// ȸ��� ������ Ŭ����, PhoneInfoŬ������ ���
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
		cout << "��    ��: " << CPhoneInfo::m_Name << endl;
		cout << "��ȭ��ȣ: " << CPhoneInfo::m_Number << endl;
		cout << "ȸ    ��: " << m_Company << endl;
	}
};

#endif __COMP_PHONE_H__