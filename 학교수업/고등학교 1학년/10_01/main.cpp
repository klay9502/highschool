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

void main()
{
	int ch;
	int i, j;
	BOOL bFound;
	int count;

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
				Score += 7 - Enemy[i].nFrame;
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
					puts(arEnemy[Enemy[i].Type]);

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
		puts(" .oOo. ");
		gotoxy(0, 24);
		printf("���� = %d", Score);

		// �ʴ� 100 ������
		delay(10);
	}
}