#ifndef __CLASS_UNIT_H__
#define __CLASS_UNIT_H__

#include "MainHeader.h"

// 모든 유닛의 슈퍼클래스
class CUnit
{
public:
	enum { DEAD = 0, LIVE };
	int		m_EndemicNumber;		// 고유번호
	char*	m_Name;					// 이름
	int		m_HP;					// 체력
	int		m_AttackPower;			// 공격력
	int		m_DefendPower;			// 방어력
	bool	m_Alive;				// 생존여부
	bool 	m_Mode;					// 시즈모드의 유무	// 탱크 전용

	CUnit(void);
	~CUnit(void);

	virtual void getState(void) = 0;
	virtual CUnit* setAttack(CUnit* _unit) = 0;
};

#endif __CLASS_UNIT_H__