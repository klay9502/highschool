#ifndef __CLASS_UNIT_MARINE_H__
#define __CLASS_UNIT_MARINE_H__

#include "UnitHandler.h"
#include "Unit.h"

// CUnit Ŭ������ ���
class CUnitMarine : public CUnit
{
public:
	CUnitMarine(void);
	~CUnitMarine(void);

	virtual void getState(void);
	virtual CUnit* setAttack(CUnit* _unit);
};

#endif __CLASS_UNIT_MARINE_H__