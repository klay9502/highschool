#ifndef __CLASS_UNIT_HANDLER_H__
#define __CLASS_UNIT_HANDLER_H__

#include "MainHeader.h"
#include "Unit.h"
#include "UnitMarine.h"
#include "UnitTank.h"
#include "UnitMedic.h"

class CUnitHandler
{
private:
	CUnit* m_pUnit[30];
public:
	CUnitHandler(void);
	~CUnitHandler(void);

	void UnitMake(void);		// 유닛 생성 함수
	void ShowBattle(CUnit* _attack, CUnit* _defend);

	// main함수에 필요한 함수
	void ShowMenu(void);		// 메뉴 출력 함수
	void UnitState(void);		// 유닛상태 출력 함수
	void UnitBattle(void);		// 유닛 전투 함수
};

#endif __CLASS_UNIT_HANDLER_H__