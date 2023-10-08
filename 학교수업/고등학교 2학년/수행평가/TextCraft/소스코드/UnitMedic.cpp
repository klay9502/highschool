#include "UnitMedic.h"


CUnitMedic::CUnitMedic(void)
{
	m_HP			= 60;		// ü�� �ʱ�ȭ
	m_AttackPower	= 20;		// ġ���� �ʱ�ȭ
	m_DefendPower	= 0;		// ���� �ʱ�ȭ
	m_Alive			= true;		// ��Ҵٰ� �ʱ�ȭ

	m_Name = new char[strlen("Medic") + 1];
	strcpy(m_Name, "Medic");
}

CUnitMedic::~CUnitMedic(void)
{
	delete[] m_Name;
}

void CUnitMedic::getState(void)
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

CUnit* CUnitMedic::setAttack(CUnit* _unit)
{
	_unit->m_HP = _unit->m_HP + m_AttackPower;

	return _unit;
}