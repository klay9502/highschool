#ifndef __CLASS_UNIT_TANK_H__
#define __CLASS_UNIT_TANK_H__

#include "UnitHandler.h"
#include "Unit.h"

// CUnit Ŭ������ ���
class CUnitTank : public CUnit
{
public:
	CUnitTank(void);
	~CUnitTank(void);

	virtual void getState(void);
	virtual CUnit* setAttack(CUnit* _unit);
};

#endif __CLASS_UNIT_TANK_H__
