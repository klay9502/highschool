#include "UnitMarine.h"


CUnitMarine::CUnitMarine(void)
{
	m_HP			= 40;		// ü�� �ʱ�ȭ
	m_AttackPower	= 6;		// ���ݷ� �ʱ�ȭ
	m_DefendPower	= 0;		// ���� �ʱ�ȭ
	m_Alive			= true;		// ��Ҵٰ� �ʱ�ȭ

	m_Name = new char[strlen("Marine") + 1];
	strcpy(m_Name, "Marine");
}

CUnitMarine::~CUnitMarine(void)
{
	delete[] m_Name;
}

void CUnitMarine::getState(void)
{
	cout << "Number: " << m_EndemicNumber << endl;
	cout << "Name: " << m_Name << endl;
	cout << "HP: " << m_HP << endl;
	cout << "Alive: ";
	switch (m_Alive)
	{
	case DEAD:
		cout << "Dead" << endl;
		break;
	case LIVE:
		cout << "Live" << endl;
		break;
	}
	cout << endl;
}

CUnit* CUnitMarine::setAttack(CUnit* _unit)
{
	_unit->m_HP = _unit->m_HP - (m_AttackPower - _unit->m_DefendPower);

	return _unit;
}