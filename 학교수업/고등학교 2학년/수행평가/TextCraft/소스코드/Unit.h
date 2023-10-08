#ifndef __CLASS_UNIT_H__
#define __CLASS_UNIT_H__

#include "MainHeader.h"

// ��� ������ ����Ŭ����
class CUnit
{
public:
	enum { DEAD = 0, LIVE };
	int		m_EndemicNumber;		// ������ȣ
	char*	m_Name;					// �̸�
	int		m_HP;					// ü��
	int		m_AttackPower;			// ���ݷ�
	int		m_DefendPower;			// ����
	bool	m_Alive;				// ��������
	bool 	m_Mode;					// �������� ����	// ��ũ ����

	CUnit(void);
	~CUnit(void);

	virtual void getState(void) = 0;
	virtual CUnit* setAttack(CUnit* _unit) = 0;
};

#endif __CLASS_UNIT_H__