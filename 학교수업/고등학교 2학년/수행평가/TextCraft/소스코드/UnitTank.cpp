#include "UnitTank.h"


CUnitTank::CUnitTank(void)
{
	m_HP			 = 150;		// 체력 초기화
	m_AttackPower	 = 30;		// 공격력 초기화
	m_DefendPower	 = 1;		// 방어력 초기화
	m_Alive			 = true;	// 살았다고 초기화
	m_Mode			 = false;	// 퉁퉁포 모드로 초기화

	m_Name = new char[strlen("Tank") + 1];
	strcpy(m_Name, "Tank");
}

CUnitTank::~CUnitTank(void)
{
	delete[] m_Name;
}

void CUnitTank::getState(void)
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
	cout << "Mode: ";
	switch (m_Mode)
	{
	case false:
		cout << "Normal" << endl;
		break;
	case true:
		cout << "Siege" << endl;
		break;
	}

	cout << endl;
}

CUnit* CUnitTank::setAttack(CUnit* _unit)
{
	_unit->m_HP = _unit->m_HP - (m_AttackPower - _unit->m_DefendPower);

	return _unit;
}