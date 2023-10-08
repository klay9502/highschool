#include "Turboc.h"
#define TRUE 1
#define FALSE 0

void PrintMain(void);
int PressSpace(void);
void PrintPower(void);
void MoveArrow(void);

int power = 0;

int main(void)
{
	int keydown, ch;

	setcursortype( NOCURSOR );
	PrintMain();

	while (1)
	{
		keydown = PressSpace();
		PrintPower();

		if ( keydown == FALSE && power > 0 )
		{
			MoveArrow();

			while (2)
			{
				if ( kbhit() )
				{
					gotoxy(0, 7);
					printf("PRESS ENTER");
					ch = getch();
					
					if ( ch == 13 )
					{
						power = 0;
						keydown = FALSE;
						clrscr();
						break;
					}
				}
			}
			PrintMain();
		}
		delay(100);
	}
	return 0;
}

void PrintMain(void)
{
	printf(" ∞\n");		// 仃
	printf(" 托△\n");		// 仆, 中
	printf(" ∥\n");		// 之

	for ( int i = 0; i < 40; i++ )
		printf("式");
	printf("忙式式式式忖\n");
	printf("弛@       弛\n");
	printf("戌式式式式戎\n");
	printf("PRESS SPACE\n");
}

int PressSpace(void)
{
	if ( GetAsyncKeyState(VK_SPACE)&0x8000 )
	{
		if ( power >= 7 )
			power = 0;
		power++;
		return TRUE;
	}
	else
		return FALSE;
}

void PrintPower(void)
{
	gotoxy(3, 5);

	for ( int i = 0; i < power; i++ )
	{
		if ( power == 1 )
		{
			printf(")      ");
		}
		else
		{
			printf(")");
		}
	}
}

void MoveArrow()
{
	int i;

	for ( i = 0; i < power * 10; i++ )
	{
		if ( (i + 1) == (power * 10) )
		{
			gotoxy(5 + i, 1);
			printf("  ");
			gotoxy(5 + i - 1, 2);
			printf("⊥");
		}
		else
		{
			gotoxy(5+i, 1);
			printf("⊥");
		}
		delay(10);
	}
	gotoxy(power * 10 + 2, 4);
	printf("%dM", power * 10);
}