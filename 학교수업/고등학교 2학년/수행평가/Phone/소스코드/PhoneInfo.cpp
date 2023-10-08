#include "PhoneCommon.h"
#include "PhoneInfo.h"


CPhoneInfo::CPhoneInfo(char* _Name, char* _Number)
{
	m_Name = new char[strlen(_Name) + 1];
	strcpy(m_Name, _Name);

	m_Number = new char[strlen(_Number) + 1];
	strcpy(m_Number, _Number);
}

CPhoneInfo::~CPhoneInfo(void)
{
	delete[] m_Number;
	delete[] m_Name;
}