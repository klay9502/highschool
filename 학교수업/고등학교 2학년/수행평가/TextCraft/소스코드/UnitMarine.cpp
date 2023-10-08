#include "UnitMarine.h"


CUnitMarine::CUnitMarine(void)
{
	m_HP			= 40;		// 체력 초기화
	m_AttackPower	= 6;		// 공격력 초기화
	m_DefendPower	= 0;		// 방어력 초기화
	m_Alive			= true;		// 살았다고 초기화

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