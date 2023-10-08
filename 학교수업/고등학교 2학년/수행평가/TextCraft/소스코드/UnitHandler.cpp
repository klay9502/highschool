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
	// 30마리 초기화
	for (int i = 0; i < MAX_UNIT; i++)
	{
		if (i >= 30)
		{
			break;
		}

		m_pUnit[i*TYPE_UNIT + 0] = new CUnitMarine;		// 마린 초기화
		m_pUnit[i*TYPE_UNIT + 1] = new CUnitTank;		// 탱크 초기화
		m_pUnit[i*TYPE_UNIT + 2] = new CUnitMedic;		// 메딕 초기화
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

		// 공격자와 방어자가 같으면 컨티뉴
		if (atcTemp == defTemp)
		{
			continue;
		}

		// 공격자가 죽으면 컨티뉴
		if (m_pUnit[atcTemp]->m_Alive == false)
		{
			continue;
		}

		// 방어자가 죽으면 컨티뉴
		if (m_pUnit[defTemp]->m_Alive == false)
		{
			continue;
		}

		// 만약 공격자가 탱크이고 tankTemp가 1(참)일 때
		if ( strcmp(m_pUnit[atcTemp]->m_Name, "Tank") == 0 && tankTemp == 1)
		{
			// 퉁퉁포모드이면 시즈모드로 변경
			if (m_pUnit[atcTemp]->m_Mode == false)
			{
				m_pUnit[atcTemp]->m_Mode = true;
				cout << m_pUnit[atcTemp]->m_EndemicNumber << " " << m_pUnit[atcTemp]->m_Name << " is SIEGE MODE!!!" << endl;
			} 
			// 시즈모드이면 퉁퉁포모드로 변경
			else if (m_pUnit[atcTemp]->m_Mode == true)
			{
				m_pUnit[atcTemp]->m_Mode = false;
				cout << m_pUnit[atcTemp]->m_EndemicNumber << " " << m_pUnit[atcTemp]->m_Name << " is NORMAL MODE!!!" << endl;
			}
		}

		// 전투 계산
		m_pUnit[defTemp] = m_pUnit[atcTemp]->setAttack(m_pUnit[defTemp]);
		ShowBattle(m_pUnit[atcTemp], m_pUnit[defTemp]);

		// 만약 죽었다면;
		if (m_pUnit[defTemp]->m_HP <= 0)
		{
			// 라이프값 변경 및 데드텍스트 출력
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