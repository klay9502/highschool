#include "UnitHandler.h"


CUnitHandler::CUnitHandler(void)
{

}

CUnitHandler::~CUnitHandler(void)
{
	for (int i = 0; i < MAX_UNIT; i++)
	{
		delete m_pUnit[i];
	}
}

void CUnitHandler::ShowMenu(void)
{
	cout << "1. Unit State" << endl;
	cout << "2. Unit Battle" << endl;
	cout << "3. Quit" << endl;
}

void CUnitHandler::UnitMake(void)
{
	// 30���� �ʱ�ȭ
	for (int i = 0; i < MAX_UNIT; i++)
	{
		if (i >= 30)
		{
			break;
		}

		m_pUnit[i*TYPE_UNIT + 0] = new CUnitMarine;		// ���� �ʱ�ȭ
		m_pUnit[i*TYPE_UNIT + 1] = new CUnitTank;		// ��ũ �ʱ�ȭ
		m_pUnit[i*TYPE_UNIT + 2] = new CUnitMedic;		// �޵� �ʱ�ȭ
		m_pUnit[i]->m_EndemicNumber = i;
	}

	cout << "Unit Creating...SUCCESS!" << endl << endl;
}

void CUnitHandler::UnitState(void)
{
	cout << "============================" << endl << endl;;
	for (int i = 0; i < MAX_UNIT; i++)
	{
		m_pUnit[i]->getState();
	}
	cout << "============================" << endl << endl;
}

void CUnitHandler::UnitBattle(void)
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < 100; i++)
	{
		int atcTemp = rand() % 30;
		int defTemp = rand() % 30;
		int tankTemp = rand() % 2;

		// �����ڿ� ����ڰ� ������ ��Ƽ��
		if (atcTemp == defTemp)
		{
			continue;
		}

		// �����ڰ� ������ ��Ƽ��
		if (m_pUnit[atcTemp]->m_Alive == false)
		{
			continue;
		}

		// ����ڰ� ������ ��Ƽ��
		if (m_pUnit[defTemp]->m_Alive == false)
		{
			continue;
		}

		// ���� �����ڰ� ��ũ�̰� tankTemp�� 1(��)�� ��
		if ( strcmp(m_pUnit[atcTemp]->m_Name, "Tank") == 0 && tankTemp == 1)
		{
			// ����������̸� ������� ����
			if (m_pUnit[atcTemp]->m_Mode == false)
			{
				m_pUnit[atcTemp]->m_Mode = true;
				cout << m_pUnit[atcTemp]->m_EndemicNumber << " " << m_pUnit[atcTemp]->m_Name << " is SIEGE MODE!!!" << endl;
			} 
			// �������̸� ���������� ����
			else if (m_pUnit[atcTemp]->m_Mode == true)
			{
				m_pUnit[atcTemp]->m_Mode = false;
				cout << m_pUnit[atcTemp]->m_EndemicNumber << " " << m_pUnit[atcTemp]->m_Name << " is NORMAL MODE!!!" << endl;
			}
		}

		// ���� ���
		m_pUnit[defTemp] = m_pUnit[atcTemp]->setAttack(m_pUnit[defTemp]);
		ShowBattle(m_pUnit[atcTemp], m_pUnit[defTemp]);

		// ���� �׾��ٸ�;
		if (m_pUnit[defTemp]->m_HP <= 0)
		{
			// �������� ���� �� �����ؽ�Ʈ ���
			m_pUnit[defTemp]->m_Alive = false;
			cout << m_pUnit[defTemp]->m_EndemicNumber << " " << m_pUnit[defTemp]->m_Name << " is DEAD!!!" << endl;
		}
	}

	cout << endl;
}

void CUnitHandler::ShowBattle(CUnit* _attack, CUnit* _defend)
{
	cout << _attack->m_EndemicNumber << " " << _attack->m_Name << " --Attack!--> " << _defend->m_EndemicNumber << " " << _defend->m_Name << endl;
}