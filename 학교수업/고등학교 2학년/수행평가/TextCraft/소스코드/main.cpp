#include "MainHeader.h"
#include "UnitHandler.h"

int main(void)
{
	CUnitHandler handler;
	int choice;

	handler.UnitMake();		// ���� ����

	while (1)
	{
		handler.ShowMenu();		// �޴� ���
		cout << "Input: ";		// �Է�
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case UNIT_STATE:
			handler.UnitState();	// ���� ���� ���
			break;
		case BALLTE:
			handler.UnitBattle();	// ���� �ǽ�
			break;
		case END:
			exit(0);			// return 0;�� �˼����� ������ exit(0); ���
		}
	}

	return 0;
}