#ifndef __CLASS_PHONEINFO_H__
#define __CLASS_PHONEINFO_H__


// Phone�� ����Ŭ����
class CPhoneInfo
{
public:
	// ShowInfo()�Լ��� ���� ����Ŭ�������� ����ؾ� �ϹǷ�
	// private ��� public�� ����ߴ�.
	char* m_Name;
	char* m_Number;

	CPhoneInfo(char* _m_Name, char* _m_Number);
	~CPhoneInfo();

	// ���� �����Լ�
	virtual void ShowInfo(void) const = 0;
};


#endif __CLASS_PHONEINFO_H__