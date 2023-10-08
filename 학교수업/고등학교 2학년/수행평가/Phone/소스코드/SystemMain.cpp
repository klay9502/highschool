#include "PhoneCommon.h"
#include "PhoneHandler.h"

int main(void)
{
	CPhoneHandler Handler;
	int choice;

	while (1)
	{
		Handler.ShowMenu();		// �޴� ���
		cout << "����: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case CREATE:	// ����
			Handler.CreateInfo();
			break;
		case SEARCH:	// �˻�
			Handler.SearchInfo();
			break;
		case DELETE:	// ����
			Handler.DeleteInfo();
			break;
		case PRINT:		// ���
			Handler.PrintInfo();
			break;
		case END:		// ����
			return 0;
		}
	}

	return 0;
}