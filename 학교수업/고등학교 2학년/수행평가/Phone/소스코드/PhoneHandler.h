#ifndef __PHONE_HANDLER_H__
#define __PHONE_HANDLER_H__

#include "PhoneCommon.h"
#include "PhoneInfo.h"

#include "NormalPhone.h"
#include "UnivPhone.h"
#include "CompPhone.h"

class CPhoneHandler
{
private:
	CPhoneInfo* m_InfoArray[128];	// ������ �迭
	int			m_InfoNum = 0;		// ������ �������� ��ȣ
public:
	CPhoneHandler(void);
	~CPhoneHandler(void);

	void ShowMenu(void) const;		// �޴� ���
	void CreateInfo(void);			// ������ ����
	void CreateNormalInfo(void);	// �Ϲ� ������ ����
	void CreateUnivInfo(void);		// ���л� ������ ����
	void CreateCompInfo(void);		// ȸ��� ������ ����
	void DeleteInfo(void);			// ������ ����
	void SearchInfo(void) const;	// ������ �˻�
	void PrintInfo(void) const ;	// ������ ��� ���
};


#endif __PHONE_HANDLER_H__