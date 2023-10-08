#ifndef __CLASS_PHONEINFO_H__
#define __CLASS_PHONEINFO_H__


// Phone의 슈퍼클래스
class CPhoneInfo
{
public:
	// ShowInfo()함수를 통해 서브클래스들이 사용해야 하므로
	// private 대신 public을 사용했다.
	char* m_Name;
	char* m_Number;

	CPhoneInfo(char* _m_Name, char* _m_Number);
	~CPhoneInfo();

	// 순수 가상함수
	virtual void ShowInfo(void) const = 0;
};


#endif __CLASS_PHONEINFO_H__