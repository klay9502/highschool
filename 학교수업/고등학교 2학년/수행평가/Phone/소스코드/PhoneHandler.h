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
	CPhoneInfo* m_InfoArray[128];	// 데이터 배열
	int			m_InfoNum = 0;		// 마지막 데이터의 번호
public:
	CPhoneHandler(void);
	~CPhoneHandler(void);

	void ShowMenu(void) const;		// 메뉴 출력
	void CreateInfo(void);			// 데이터 생성
	void CreateNormalInfo(void);	// 일반 데이터 생성
	void CreateUnivInfo(void);		// 대학생 데이터 생성
	void CreateCompInfo(void);		// 회사원 데이터 생성
	void DeleteInfo(void);			// 데이터 삭제
	void SearchInfo(void) const;	// 데이터 검색
	void PrintInfo(void) const ;	// 데이터 모두 출력
};


#endif __PHONE_HANDLER_H__