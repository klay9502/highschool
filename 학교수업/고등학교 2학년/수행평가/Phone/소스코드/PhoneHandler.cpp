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

void CPhoneHandler::ShowMenu(void) const	// �޴� ���
{
	cout << "�����ϼ���..." << endl;
	cout << "1. ������ �Է�" << endl;
	cout << "2. ������ �˻�" << endl;
	cout << "3. ������ ����" << endl;
	cout << "4. ������ ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void CPhoneHandler::CreateInfo(void)		// ������ ����
{
	int choice;
	
	cout << "������ �Է��� �����մϴ�.";
	cout << "1. �Ϲ�, 2. ����, 3. ȸ��" << endl;
	cout << "����: ";
	cin >> choice;

	switch (choice)
	{
	case NORMAL:
		CreateNormalInfo();				// �Ϲ� ������
		break;
	case UNIV:
		CreateUnivInfo();				// ���л� ������
		break;
	case COMP:
		CreateCompInfo();				// ȸ��� ������
		break;
	}
}

void CPhoneHandler::CreateNormalInfo(void)	// �Ϲ� ������ ����
{
	char name[LPSTR_LEN];
	char number[LPSTR_LEN];

	// �Է�
	cout << "��    ��: "; cin >> name;
	cout << "��ȭ��ȣ: "; cin >> number;
	cout << endl;

	// InfoArray�� CNormalPhone Ŭ������ �Ҵ� �� ������ ����
	m_InfoArray[m_InfoNum++] = new CNormalPhone(name, number);
}

void CPhoneHandler::CreateUnivInfo(void)	// ���л� ������ ����
{
	char name[LPSTR_LEN];
	char number[LPSTR_LEN];
	char major[LPSTR_LEN];
	int grade;

	// �Է�
	cout << "��    ��: "; cin >> name;
	cout << "��ȭ��ȣ: "; cin >> number;
	cout << "��    ��: "; cin >> major;
	cout << "��    ��: "; cin >> grade;
	cout << endl;

	// InfoArray�� CUnivPhone Ŭ������ �Ҵ� �� ������ ����
	m_InfoArray[m_InfoNum++] = new CUnivPhone(name, number, major, grade);
}

void CPhoneHandler::CreateCompInfo(void)	// ȸ��� ������ ����
{
	char name[LPSTR_LEN];
	char number[LPSTR_LEN];
	char company[LPSTR_LEN];

	// �Է�
	cout << "��    ��: "; cin >> name;
	cout << "��ȭ��ȣ: "; cin >> number;
	cout << "ȸ    ��: "; cin >> company;
	cout << endl;

	// InfoArray�� CCompPhone Ŭ������ �Ҵ� �� ������ ����
	m_InfoArray[m_InfoNum++] = new CCompPhone(name, number, company);
}

void CPhoneHandler::DeleteInfo(void)	// ������ ����
{
	char name[LPSTR_LEN];

	cout << "������ �������� �̸��� �Է��ϼ���.";
	cout << "�̸�: "; cin >> name;

	for (int i = 0; i < m_InfoNum; i++)
	{
		// ���� �Է��� �̸��� �������� �̸��� ���� ���
		if (strcmp(name, m_InfoArray[i]->m_Name) == 0)
		{
			// �����͸� �����
			m_InfoArray[i] = NULL;

			// InfoArray�迭�� ������ ä��� ���� �����͹迭�� ��ĭ�� �մ��
			for (int j = i + 1; j < m_InfoNum; j++)
			{
				m_InfoArray[j - 1] = m_InfoArray[j];
			}
			m_InfoNum--;
			cout << "���� �Ϸ�" << endl << endl;
			return;
		}
	}

	cout << "ERROR! :: �����͸� ã�� ���� �����ϴ�." << endl << endl;
}

void CPhoneHandler::SearchInfo(void) const	// ������ �˻�
{
	char name[LPSTR_LEN];

	cout << "������ �˻��� �����մϴ�.";
	cout << "�̸�: "; cin >> name;

	for (int i = 0; i < m_InfoNum; i++)
	{
		// ���� �Է��� �̸��� �������� �̸��� ���� ��� 
		if (strcmp(name, m_InfoArray[i]->m_Name) == 0)
		{
			// ������ ���� ���
			m_InfoArray[i]->ShowInfo();
			cout << endl;
			return;
		}
	}

	cout << "ERROR! :: �����͸� ã�� ���� �����ϴ�." << endl << endl;
}

void CPhoneHandler::PrintInfo(void) const		// ������ ������ ��� ���
{
	for (int i = 0; i < m_InfoNum; i++)
	{
		m_InfoArray[i]->ShowInfo();
		cout << endl;
	}
}