#include "PhoneHandler.h"


CPhoneHandler::CPhoneHandler(void)
{
	// empty...
}

CPhoneHandler::~CPhoneHandler(void)
{
	for (int i = 0; i < m_InfoNum; i++)
	{
		delete m_InfoArray[i];
	}
}

void CPhoneHandler::ShowMenu(void) const	// 메뉴 출력
{
	cout << "선택하세요..." << endl;
	cout << "1. 데이터 입력" << endl;
	cout << "2. 데이터 검색" << endl;
	cout << "3. 데이터 삭제" << endl;
	cout << "4. 데이터 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void CPhoneHandler::CreateInfo(void)		// 데이터 생성
{
	int choice;
	
	cout << "데이터 입력을 시작합니다.";
	cout << "1. 일반, 2. 대학, 3. 회사" << endl;
	cout << "선택: ";
	cin >> choice;

	switch (choice)
	{
	case NORMAL:
		CreateNormalInfo();				// 일반 데이터
		break;
	case UNIV:
		CreateUnivInfo();				// 대학생 데이터
		break;
	case COMP:
		CreateCompInfo();				// 회사원 데이터
		break;
	}
}

void CPhoneHandler::CreateNormalInfo(void)	// 일반 데이터 생성
{
	char name[LPSTR_LEN];
	char number[LPSTR_LEN];

	// 입력
	cout << "이    름: "; cin >> name;
	cout << "전화번호: "; cin >> number;
	cout << endl;

	// InfoArray에 CNormalPhone 클래스를 할당 및 데이터 저장
	m_InfoArray[m_InfoNum++] = new CNormalPhone(name, number);
}

void CPhoneHandler::CreateUnivInfo(void)	// 대학생 데이터 생성
{
	char name[LPSTR_LEN];
	char number[LPSTR_LEN];
	char major[LPSTR_LEN];
	int grade;

	// 입력
	cout << "이    름: "; cin >> name;
	cout << "전화번호: "; cin >> number;
	cout << "전    공: "; cin >> major;
	cout << "학    년: "; cin >> grade;
	cout << endl;

	// InfoArray에 CUnivPhone 클래스를 할당 및 데이터 저장
	m_InfoArray[m_InfoNum++] = new CUnivPhone(name, number, major, grade);
}

void CPhoneHandler::CreateCompInfo(void)	// 회사원 데이터 생성
{
	char name[LPSTR_LEN];
	char number[LPSTR_LEN];
	char company[LPSTR_LEN];

	// 입력
	cout << "이    름: "; cin >> name;
	cout << "전화번호: "; cin >> number;
	cout << "회    사: "; cin >> company;
	cout << endl;

	// InfoArray에 CCompPhone 클래스를 할당 및 데이터 저장
	m_InfoArray[m_InfoNum++] = new CCompPhone(name, number, company);
}

void CPhoneHandler::DeleteInfo(void)	// 데이터 삭제
{
	char name[LPSTR_LEN];

	cout << "삭제할 데이터의 이름을 입력하세요.";
	cout << "이름: "; cin >> name;

	for (int i = 0; i < m_InfoNum; i++)
	{
		// 만약 입력한 이름과 데이터의 이름이 같을 경우
		if (strcmp(name, m_InfoArray[i]->m_Name) == 0)
		{
			// 데이터를 지우고
			m_InfoArray[i] = NULL;

			// InfoArray배열의 공백을 채우기 위해 데이터배열을 한칸씩 앞당김
			for (int j = i + 1; j < m_InfoNum; j++)
			{
				m_InfoArray[j - 1] = m_InfoArray[j];
			}
			m_InfoNum--;
			cout << "삭제 완료" << endl << endl;
			return;
		}
	}

	cout << "ERROR! :: 데이터를 찾을 수가 없습니다." << endl << endl;
}

void CPhoneHandler::SearchInfo(void) const	// 데이터 검색
{
	char name[LPSTR_LEN];

	cout << "데이터 검색을 시작합니다.";
	cout << "이름: "; cin >> name;

	for (int i = 0; i < m_InfoNum; i++)
	{
		// 만약 입력한 이름과 데이터의 이름이 같을 경우 
		if (strcmp(name, m_InfoArray[i]->m_Name) == 0)
		{
			// 데이터 정보 출력
			m_InfoArray[i]->ShowInfo();
			cout << endl;
			return;
		}
	}

	cout << "ERROR! :: 데이터를 찾을 수가 없습니다." << endl << endl;
}

void CPhoneHandler::PrintInfo(void) const		// 데이터 정보를 모두 출력
{
	for (int i = 0; i < m_InfoNum; i++)
	{
		m_InfoArray[i]->ShowInfo();
		cout << endl;
	}
}