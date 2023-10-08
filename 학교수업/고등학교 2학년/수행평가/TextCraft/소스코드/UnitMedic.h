#ifndef __CLASS_UNIT_MEDIC_H__
#define __CLASS_UNIT_MEDIC_H__

#include "UnitHandler.h"
#include "Unit.h"

// CUnit 클래스를 상속
class CUnitMedic : public CUnit
{
public:
	CUnitMedic(void);
	~CUnitMedic(void);

	virtual void getState(void);
	virtual CUnit* setAttack(CUnit* _unit);
};

#endif __CLASS_UNIT_MEDIC_H__