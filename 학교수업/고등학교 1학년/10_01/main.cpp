#include "Turboc.h"

#define ESC			27
#define MAXENEMY	20	// 적군의 최대 개수
#define MAXBALL		100	// 적군 총알의 최대 개수

int fx;
int bx, by;
int Score;

struct tag_Enemy	// 적군의 정보
{
	BOOL exist;		// 신호의 존재 여부
	int Type;		// *arEnemy[]배열 값을 가짐
	int x, y;		// 현재좌표
	int Delta;		// 적군이 이동할 방향 1 또는 -1
	int nFrame;		// 속도
	int nStay;		// 속도에 대한 카운트
} Enemy[MAXENEMY];

struct tag_Ball		// 적군 총알의 정보
{
	BOOL exist;		// 신호의 존재 여부
	int x, y;		// 현재좌표
	int nFrame;		// 속도
	int nStay;		// 속도에 대한 카운트
} Ball[MAXBALL];

char *arEnemy[] = {" ;:^:; ", " zZWZz ", " o0@0o ", " <-=-> "};	// 적군의 4가지

BOOL IsKeyDown(int Key)
{
	return ( (GetAsyncKeyState(Key) & 0x8000) != 0 );
}

void main()
{
	int ch;
	int i, j;
	BOOL bFound;
	int count;

	randomize();
	clrscr();
	setcursortype(NOCURSOR);

	// 주인공 좌표 및 점수 초기화
	fx = 40;
	bx = -1;
	Score = 0;

	for (count = 0; ; count++)
	{
		// 좌우 이동 처리
		if ( count % 5 == 0 )		// 초당 100프레임이면 속도가 빠르기 때문에 count변수로 입력 주기를 조절
		{
			if ( IsKeyDown(VK_LEFT) )
			{
				if ( fx > 6 )
					fx--;
			}

			if ( IsKeyDown(VK_RIGHT) )
			{
				if ( fx < 72 )
					fx++;
			}
		}

		// 키 입력 처리
		if ( kbhit() )
		{
			ch = getch();

			if ( ch == 0xE0 || ch == 0 )
			{
				getch();
			}
			else
			{
				switch ( ch )
				{
				case ' ':
					if ( bx == -1 )
					{
						bx = fx;
						by = 23;
					}
					break;
				case ESC:
					setcursortype(NORMALCURSOR);
					exit(1);
				}
			}
		}

		// 적군 생성
		if ( random(100) == 0 )		// 100분의 1확률로 적군을 생성 따라서 초당 1번의 적군이 나타남 
		{
			for (i = 0; i < MAXENEMY && Enemy[i].exist == TRUE; i++) {;}
			if ( i != MAXENEMY)
			{
				if ( random(2) == 1 )
				{
					Enemy[i].x = 5;
					Enemy[i].Delta = 1;	// Delta가 1이면 적군이 왼쪽에서 오른쪽으로 이동
				}
				else
				{
					Enemy[i].x = 75;
					Enemy[i].Delta = -1;	// Delta가 -1이면 적군이 오른쪽에서 왼쪽으로 이동
				}

				for (;;)
				{
					Enemy[i].y = random(10) + 1;

					for (bFound = FALSE, j = 0; j < MAXENEMY; j++)
					{
						if ( Enemy[j].exist == TRUE && Enemy[j].y == Enemy[i].y )
						{
							// 한줄에 적군이 둘이 있을 수 없으므로 이미 만들어진 적군과 y좌표가 중복되는지 검사하는 코드
							bFound = TRUE;
							break;
						}
					}

					if ( bFound == FALSE )
					{
						break;
					}
				}

				Enemy[i].nFrame = Enemy[i].nStay = random(6) + 1;
				Enemy[i].Type = random(sizeof(arEnemy) / sizeof(arEnemy[0]));
				Enemy[i].exist = TRUE;
			}
		}

		// 아군 총알 이동 및 출력

		if ( bx != -1 )
		{
			gotoxy(bx, by);
			putch(' ');

			if ( by == 0 )
			{
				bx = -1;
			}
			else
			{
				by--;
				gotoxy(bx, by);
				putch('i');
			}
		}

		// 적군과 아군 총알의 충돌 판정

		for (i = 0; i < MAXENEMY; i++)
		{
			if ( Enemy[i].exist == FALSE )
				continue;

			if ( Enemy[i].y == by && abs(Enemy[i].x - bx) <= 2 )
			{
				// 존재하지 모든 적군에 대해 총알과 y좌표가 일치하고 x좌표끼리의 차이가 2 이하일 때 충돌했다고 판단.
				gotoxy(bx, by);
				putch(' ');
				bx = -1;
				Enemy[i].exist = FALSE;
				gotoxy(Enemy[i].x - 3, Enemy[i].y);
				puts("       ");
				Score += 7 - Enemy[i].nFrame;
				break;
			}
		}

		// 적군 총알 이동
		for (i = 0; i < MAXBALL; i++)
		{
			if ( Ball[i].exist == FALSE )
				continue;

			Ball[i].nStay--;

			if ( Ball[i].nStay == 0 )
			{
				Ball[i].nStay = Ball[i].nFrame;
				gotoxy(Ball[i].x, Ball[i].y);
				putch(' ');

				if ( Ball[i].y >= 23 )
				{
					Ball[i].exist = FALSE;
				}
				else
				{
					Ball[i].y++;
					gotoxy(Ball[i].x, Ball[i].y);
					putch('!');
				}
			}
		}

		// 적군 총알과 아군의 충돌 판정
		for (i = 0; i < MAXBALL; i++)
		{
			if ( Ball[i].exist == FALSE )
				continue;

			if ( Ball[i].y == 23 && abs(Ball[i].x - fx) <= 2 )
			{
				gotoxy(fx - 3, 21);
				puts("   .   ");
				gotoxy(fx - 3, 22);
				puts(" .  . .");
				gotoxy(fx - 4, 23);
				puts("..:V:..");
				delay(2000);
				setcursortype(NORMALCURSOR);
				exit(1);
			}
		}

		// 적군 이동 및 출력
		for (i = 0; i < MAXENEMY; i++)
		{
			if ( Enemy[i].exist == FALSE )
				continue;

			Enemy[i].nStay--;

			if ( Enemy[i].nStay == 0 )
			{
				Enemy[i].nStay = Enemy[i].nFrame;

				if ( Enemy[i].x >= 76 || Enemy[i].x <= 4 )
				{
					Enemy[i].exist = FALSE;
					gotoxy(Enemy[i].x - 3, Enemy[i].y);
					puts("       ");
				}
				else
				{
					Enemy[i].x += Enemy[i].Delta;
					gotoxy(Enemy[i].x - 3, Enemy[i].y);
					puts(arEnemy[Enemy[i].Type]);

					// 총알 발사
					if ( random(10) == 0 )
					{
						for (j = 0; j < MAXBALL && Ball[j].exist == TRUE; j++) {;}

						if ( j != MAXBALL )
						{
							Ball[j].x = Enemy[i].x + 2;
							Ball[j].y = Enemy[i].y + 1;
							Ball[j].nFrame = Ball[j].nStay = Enemy[i].nFrame * 6;
							Ball[j].exist = TRUE;
						}
					}
				}
			}
		}

		// 주인공 및 점수 출력
		gotoxy(fx - 3, 23);
		puts(" .oOo. ");
		gotoxy(0, 24);
		printf("점수 = %d", Score);

		// 초당 100 프레임
		delay(10);
	}
}