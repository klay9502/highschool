#include "Turboc.h"
#define LEFT		75
#define RIGHT		77
#define UP			72
#define DOWN		80
#define ENTER		13
#define MAXSTAGE	3

void DrawScreen();		//ns �迭�� ������ �״�� ȭ�鿡 ���
BOOL TestEnd();			// ������ ������ â�� ��ġ�� ������ �̵� �Ǿ������� �˻�
void Move(int dir);

char ns[18][21];			// �� ���������� ������ �迭
int nStage;
int nx, ny;
int nMove;
int tp_x, tp_y;

bool cheat_mole = false;
bool cheat_build = false;

char arStage[MAXSTAGE][18][21] = {				// �� �迭
	{
		"####################",
		"####################",
		"####################",
		"#####           ####",
		"#####0  ############",
		"#####  0############",
		"###  0 0 ###########",
		"### # ##############",
		"#   # ########  ..##",
		"# 0      @ ###  ..##",
		"##############  ..##",
		"######## 0##########",
		"####################",
		"####################",
		"####################",
		"####################",
		"####################",
		"####################"
	},
	{
		"####################",
		"####################",
		"####################",
		"####################",
		"####..  #     ######",
		"####..  # 0  0  ####",
		"####..  #0####  ####",
		"####..  # @ ##  ####",
		"####..  # #  0 #####",
		"######### ##0 0 ####",
		"###### 0 #0 0 0 ####",
		"######   ##     ####",
		"####################",
		"####################",
		"####################",
		"####################",
		"####################",
		"####################"
	},
	{
		"####################",
		"####################",
		"####################",
		"####################",
		"##########     @####",
		"########## 0#0 #####",
		"########## 0  0#####",
		"###########0#0 #####",
		"########## 0########",
		"##....  ## 0# 0  ###",
		"###...    0 #0   ###",
		"##....  ############",
		"####################",
		"####################",
		"####################",
		"####################",
		"####################",
		"####################"
	}
};

void main()
{
	int ch;
	int x, y;

	setcursortype( NOCURSOR );
	nStage = 0;

	while (1)
	{
		memcpy (ns, arStage[nStage], sizeof(ns) );

		//for (y = 0; y = 18; y++)
		//{
		//	for (x = 0; x < 20; x++)
		//	{
		//		ns[y][x] = arStage[nStage][y][x];
		//	}
		//}
		
		for (y = 0; y < 18; y++)
		{
			for (x = 0; x < 20; x++)
			{
				if (ns[y][x] == '@')
				{
					nx = x;
					ny = y;
					ns[y][x] = ' ';
				}
			}
		}

		clrscr();
		nMove = 0;

		while(2)	// 2�� ����, �������� �ϳ��� ���δ� ����
		{
			DrawScreen();
			ch = getch();

			if (ch == 0xE0 || ch == 0)
			{
				ch = getch();
				switch (ch)
				{
				case LEFT:
				case RIGHT:
				case UP:
				case DOWN:
					Move(ch);
					break;
				}
			}
			else
			{
				ch = tolower(ch);
				
				if (ch == 'r')
					break;

				if (ch == 'n')
				{
					if (nStage < MAXSTAGE-1)
					{
						nStage++;
					}
					break;
				}

				if (ch == 'p')
				{
					if (nStage > 0)
					{
						nStage--;
					}
					break;
				}

				if (ch == 'q')
				{
					setcursortype(NORMALCURSOR);
					exit(0);
				}

				if (ch == 'm')
				{
					if (cheat_mole == false)
					{
						cheat_mole = true;
						gotoxy(0, 20); printf("\aCOMMAND :: CHEAT_MOLE ON...");
					}
					else if (cheat_mole == true)
					{
						cheat_mole = false;
						gotoxy(0, 20); printf("\aCOMMAND :: CHEAT_MOLE OFF...");
					}
					delay(500);
					clrscr();
				}

				if (ch == 'b')
				{
					if (cheat_build == false)
					{
						cheat_build  = true;
						gotoxy(0, 20); printf("\aCOMMAND :: CHEAT_BUILD ON...");
					}
					else if (cheat_build == true)
					{
						cheat_build = false;
						gotoxy(0, 20); printf("\aCOMMAND :: CHEAT_BUILD OFF...");
					}
					delay(500);
					clrscr();
				}

			}
			if (TestEnd())
			{
				clrscr();
				gotoxy(10, 10);
				printf("%d ���������� Ǯ�����ϴ�. ���� ���������� �̵��մϴ�.", nStage + 1);
				delay(2000);

				if (nStage < MAXSTAGE - 1)
				{
					nStage++;
				}
				break;
			}
		}
	}
}

void DrawScreen()
{
	int x, y;

	for (y = 0; y < 18; y++)
	{
		for (x = 0; x < 20; x++)
		{
			gotoxy(x, y);
			printf("%c", ns[y][x]);
		}
	}
	gotoxy(nx, ny);
	printf("%c", '@');

	gotoxy(40, 2); puts("CHEAT SOKOBAN");
	gotoxy(40, 4); puts("Q:����, R:�ٽ� ����");
	gotoxy(40, 6); puts("N:���� ,P:����");
	gotoxy(40, 8); printf("�������� : %d", nStage + 1);
	gotoxy(40, 10); printf("�̵� ȸ�� : %d", nMove);
}

BOOL TestEnd()
{
	int x, y;

	for (y = 0; y < 18; y++)
	{
		for (x = 0; x < 20; x++)
		{
			if (arStage[nStage][y][x] == '.' && ns[y][x] != '0')
			// if (arStage[nStage][y][x] == '.' && ns[y][x] != '!')
			{
				return FALSE;
			}
		}
	}
	return TRUE;
}

void Move(int dir)
{
	int dx = 0, dy = 0;

	switch (dir)
	{
	case LEFT:
		dx = -1;
		break;
	case RIGHT:
		dx = 1;
		break;
	case UP:
		dy = -1;
		break;
	case DOWN:
		dy = 1;
		break;
	}

	if (ns[ny + dy][nx + dx] == '#' && cheat_mole == true)		// �δ��� ġƮ
	{
		ns[ny + dy][nx + dx] = ' ';

		nx += dx;
		ny += dy;
		nMove++;
	}
	else if (ns[ny + dy][nx + dx] != '#' && cheat_build == true)		// ���� ġƮ
	{
		if (ns[ny + dy][nx + dx] == '0')
		{
			if (ns[ny + dy * 2][nx + dx * 2] == ' ' || ns[ny + dy * 2][nx + dx * 2] == '.')
			{
				if (arStage[nStage][ny + dy][nx + dx] == '.')
				{
					ns[ny + dy][nx + dx] = '.';
				}
				else
				{
					ns[ny + dy][nx + dx] = ' ';
				}
				ns[ny + dy * 2][nx + dx * 2] = '0';
			}
			else
			{
				return;
			}
		}
		else
		{
			ns[ny + dy][nx + dx] = '#';
		}

		nx += dx;
		ny += dy;
		nMove++;
	}
	else if (ns[ny + dy][nx + dx] != '#')
	{
		// if (ns[ny + dy][nx + dx] == '0' || ns[ny + dy * 2][nx + dx * 2] == '!')
		if (ns[ny + dy][nx + dx] == '0')
		{
			if (ns[ny + dy * 2][nx + dx * 2] == ' ' || ns[ny + dy * 2][nx + dx * 2] == '.')
			{
				if (arStage[nStage][ny + dy][nx + dx] == '.')
				{
					ns[ny + dy][nx + dx] = '.';
				}
				else
				{
					ns[ny + dy][nx + dx] = ' ';
				}
				ns[ny + dy * 2][nx + dx * 2] = '0';
			}
			else
			{
				return;
			}
		}

		nx += dx;
		ny += dy;
		nMove++;
		
		//if (arStage[nStage][ny + dy][nx + dx] == '.' && ns[ny + dy][nx + dx] == '0')
		//{
		//	ns[ny + dy][nx + dx] = '!';
		//}
	}
}

