#include "Turboc.h"

#define ESC			27
#define MAXENEMY	20	// ������ �ִ� ����
#define MAXBALL		100	// ���� �Ѿ��� �ִ� ����

int fx;
int bx, by;
int Score;

struct tag_Enemy	// ������ ����
{
	BOOL exist;		// ��ȣ�� ���� ����
	int Type;		// *arEnemy[]�迭 ���� ����
	int x, y;		// ������ǥ
	int Delta;		// ������ �̵��� ���� 1 �Ǵ� -1
	int nFrame;		// �ӵ�
	int nStay;		// �ӵ��� ���� ī��Ʈ
} Enemy[MAXENEMY];

struct tag_Ball		// ���� �Ѿ��� ����
{
	BOOL exist;		// ��ȣ�� ���� ����
	int x, y;		// ������ǥ
	int nFrame;		// �ӵ�
	int nStay;		// �ӵ��� ���� ī��Ʈ
} Ball[MAXBALL];

char *arEnemy[] = {" ;:^:; ", " zZWZz ", " o0@0o ", " <-=-> "};	// ������ 4����

BOOL IsKeyDown(int Key)
{
	return ( (GetAsyncKeyState(Key) & 0x8000) != 0 );
}

void game();
void menu();

void menu()
{
	char ch;

	setcursortype(NOCURSOR);

	while (1)
	{
		clrscr();

		gotoxy(30, 8);
		GREEN;	printf("Cheat Shooting Game");
		gotoxy(35, 9);
		GRAY;	printf("ver 1.0.2");

		gotoxy(32, 12);
		WHITE;	printf("1. �� �� �� ��");

		gotoxy(32, 14);
		WHITE;	printf("2. �� �� �� ��");

		gotoxy(34, 18);
		GRAY;	printf("Input : ");

		WHITE;	scanf("%d", &ch);

		if (ch == 1)
		{
			clrscr();

			gotoxy(34, 11);
			GRAY;	printf("Loading...");
			WHITE;
			delay(3000);
			clrscr();
			delay(2000);
			game();
		}

		if (ch == 2)
		{
			clrscr();
			gotoxy(34, 11);
			RED;	printf("Thank You");
			delay(2000);
			exit(1);
		}
	}
}

void game()
{
	int ch;
	int i, j;
	BOOL bFound;
	int count;
	bool cheak_godmod = false;
	bool cheak_speeddownmod = false;
	bool cheak_speedupmod = false;
	bool cheak_fevermod = false;

	randomize();
	clrscr();
	setcursortype(NOCURSOR);

	// ���ΰ� ��ǥ �� ���� �ʱ�ȭ
	fx = 40;
	bx = -1;
	Score = 0;

	for (count = 0; ; count++)
	{
		// �¿� �̵� ó��
		if ( count % 5 == 0 )		// �ʴ� 100�������̸� �ӵ��� ������ ������ count������ �Է� �ֱ⸦ ����
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

		// Ű �Է� ó��
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
				case 71:
				case 103:
					if (cheak_godmod == false)
					{
						gotoxy(25, 24);
						GRAY;	printf("commend:: cheat on... God mod");
						WHITE;
						Sleep(1000);
						gotoxy(25, 24);
						printf("                             ");
						cheak_godmod = true;
						break;
					}

					if (cheak_godmod == true)
					{
						gotoxy(25, 24);
						GRAY;	printf("commend:: cheat off... God mod");
						WHITE;
						Sleep(1000);
						gotoxy(25, 24);
						printf("                              ");
						cheak_godmod = false;
						break;
					}
				case 85:
				case 117:
					if (cheak_speeddownmod == false)
					{
						if (cheak_speedupmod == false)
						{
							cheak_speedupmod = true;
							gotoxy(25, 24);
							GRAY;	printf("commend:: cheat on... SpeedUp mod");
							WHITE;
							Sleep(1000);
							gotoxy(25, 24);
							printf("                                 ");
							break;
						}

						if (cheak_speedupmod == true)
						{
							cheak_speedupmod = false;
							gotoxy(25, 24);
							GRAY;	printf("commend:: cheat off... SpeedUp mod");
							WHITE;
							Sleep(1000);
							gotoxy(25, 24);
							printf("                                  ");
							break;
						}
					}
					break;
				case 68:
				case 100:
					if (cheak_speedupmod == false)
					{
						if (cheak_speeddownmod == false)
						{
							cheak_speeddownmod = true;
							gotoxy(25, 24);
							GRAY;	printf("commend:: cheat on... SpeedDown mod");
							WHITE;
							Sleep(1000);
							gotoxy(25, 24);
							printf("                                    ");
							break;
						}

						if (cheak_speeddownmod == true)
						{
							cheak_speeddownmod = false;
							gotoxy(25, 24);
							GRAY;	printf("commend:: cheat off... SpeedDown mod");
							WHITE;
							Sleep(1000);
							gotoxy(25, 24);
							printf("                                     ");
							break;
						}
					}
					break;
				case 70:
				case 102:
					if (cheak_fevermod == false)
					{
						gotoxy(25, 24);
						GRAY;	printf("commend:: cheat on... FeverTime mod");
						WHITE;
						Sleep(1000);
						gotoxy(25, 24);
						printf("                                   ");
						cheak_fevermod = true;
						break;
					}

					if (cheak_fevermod == true)
					{
						gotoxy(25, 24);
						GRAY;	printf("commend:: cheat off... FeverTime mod");
						WHITE;
						Sleep(1000);
						gotoxy(25, 24);
						printf("                                    ");
						cheak_fevermod = false;
						break;
					}
				}
			}
		}

		// ���� ����
		if ( random(100) == 0 )		// 100���� 1Ȯ���� ������ ���� ���� �ʴ� 1���� ������ ��Ÿ�� 
		{
			for (i = 0; i < MAXENEMY && Enemy[i].exist == TRUE; i++) {;}
			if ( i != MAXENEMY)
			{
				if ( random(2) == 1 )
				{
					Enemy[i].x = 5;
					Enemy[i].Delta = 1;	// Delta�� 1�̸� ������ ���ʿ��� ���������� �̵�
				}
				else
				{
					Enemy[i].x = 75;
					Enemy[i].Delta = -1;	// Delta�� -1�̸� ������ �����ʿ��� �������� �̵�
				}

				for (;;)
				{
					Enemy[i].y = random(10) + 1;

					for (bFound = FALSE, j = 0; j < MAXENEMY; j++)
					{
						if ( Enemy[j].exist == TRUE && Enemy[j].y == Enemy[i].y )
						{
							// ���ٿ� ������ ���� ���� �� �����Ƿ� �̹� ������� ������ y��ǥ�� �ߺ��Ǵ��� �˻��ϴ� �ڵ�
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

		// �Ʊ� �Ѿ� �̵� �� ���

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

		// ������ �Ʊ� �Ѿ��� �浹 ����

		for (i = 0; i < MAXENEMY; i++)
		{
			if ( Enemy[i].exist == FALSE )
				continue;

			if ( Enemy[i].y == by && abs(Enemy[i].x - bx) <= 2 )
			{
				// �������� ��� ������ ���� �Ѿ˰� y��ǥ�� ��ġ�ϰ� x��ǥ������ ���̰� 2 ������ �� �浹�ߴٰ� �Ǵ�.
				gotoxy(bx, by);
				putch(' ');
				bx = -1;
				Enemy[i].exist = FALSE;
				gotoxy(Enemy[i].x - 3, Enemy[i].y);
				puts("       ");

				if (cheak_fevermod == false)
				{
					Score += 7 - Enemy[i].nFrame;
				}

				if (cheak_fevermod == true)
				{
					Score += 5 * (7 - Enemy[i].nFrame);
				}
				break;
			}
		}

		// ���� �Ѿ� �̵�
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

		// ���� �Ѿ˰� �Ʊ��� �浹 ����
		for (i = 0; i < MAXBALL; i++)
		{
			if ( Ball[i].exist == FALSE )
				continue;

			if ( Ball[i].y == 23 && abs(Ball[i].x - fx) <= 2 && cheak_godmod == false)
			{
				gotoxy(fx - 3, 21);
				RED;	puts("   .   ");
				gotoxy(fx - 3, 22);
				puts(" .  . .");
				gotoxy(fx - 4, 23);
				puts("..:V:..");
				delay(2000);

				clrscr();
				gotoxy(34, 11);
				printf("GAME OVER");
				gotoxy(35, 13);
				GRAY;	printf("Score ");
				WHITE;	printf("%d", Score);
				delay(3000);

				setcursortype(NORMALCURSOR);
				exit(1);
			}
		}

		// ���� �̵� �� ���
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
					SKY;	puts(arEnemy[Enemy[i].Type]);
					WHITE;

					// �Ѿ� �߻�
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

		// ���ΰ� �� ���� ���
		gotoxy(fx - 3, 23);
		GREEN;	puts(" i.0.i ");
		gotoxy(0, 24);
		WHITE;	printf("���� = %d", Score);

		if (cheak_speedupmod == false && cheak_speeddownmod == true)
		{
			delay(50);
		}

		else if (cheak_speedupmod == false && cheak_speeddownmod == false)
		{
			// �ʴ� 100 ������
			delay(10);
		}

		else if (cheak_speedupmod == true && cheak_speeddownmod == false)
		{
			delay(3);
		}
	}
}

void main()
{
	menu();
}