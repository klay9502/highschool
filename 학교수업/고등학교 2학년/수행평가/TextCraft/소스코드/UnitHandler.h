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

	void UnitMake(void);		// ���� ���� �Լ�
	void ShowBattle(CUnit* _attack, CUnit* _defend);

	// main�Լ��� �ʿ��� �Լ�
	void ShowMenu(void);		// �޴� ��� �Լ�
	void UnitState(void);		// ���ֻ��� ��� �Լ�
	void UnitBattle(void);		// ���� ���� �Լ�
};

#endif __CLASS_UNIT_HANDLER_H__