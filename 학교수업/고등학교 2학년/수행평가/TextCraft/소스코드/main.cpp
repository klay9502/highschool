#include "MainHeader.h"
#include "UnitHandler.h"

int main(void)
{
	CUnitHandler handler;
	int choice;

	handler.UnitMake();		// 유닛 생성

	while (1)
	{
		handler.ShowMenu();		// 메뉴 출력
		cout << "Input: ";		// 입력
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case UNIT_STATE:
			handler.UnitState();	// 유닛 상태 출력
			break;
		case BALLTE:
			handler.UnitBattle();	// 전투 실시
			break;
		case END:
			exit(0);			// return 0;의 알수없는 이유로 exit(0); 사용
		}
	}

	return 0;
}