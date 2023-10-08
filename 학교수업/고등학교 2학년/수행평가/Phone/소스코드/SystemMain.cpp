#include "PhoneCommon.h"
#include "PhoneHandler.h"

int main(void)
{
	CPhoneHandler Handler;
	int choice;

	while (1)
	{
		Handler.ShowMenu();		// 메뉴 출력
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case CREATE:	// 생성
			Handler.CreateInfo();
			break;
		case SEARCH:	// 검색
			Handler.SearchInfo();
			break;
		case DELETE:	// 삭제
			Handler.DeleteInfo();
			break;
		case PRINT:		// 출력
			Handler.PrintInfo();
			break;
		case END:		// 종료
			return 0;
		}
	}

	return 0;
}