/*
#include "Turboc.h"

int main(void)
{
	int x = 40;
	int y = 12;
	int ch;

	while(1)
	{
		gotoxy(x, y);
		putch('*');

		ch = getch();
		if (ch == 0xE0 || ch == 0)
		{
			ch = getch();

			switch (ch)
			{
			case 72:			// up
				if (y > 0)
					y--;
				break;
			case 80:			// down
				if (y < 24)
					y++;
				break;
			case 75:			// left
				if (x > 0)
					x--;
				break;
			case 77:			// right
				if (x < 79)
					x++;
				break;
			}
		}
	}

	return 0;
	_getch();
}
*/

#include "Turboc.h"

int main(void)
{
	int x = 40;
	int y = 12;

	while (1)
	{
		gotoxy(x, y);
		putch('&');

		if (GetAsyncKeyState(VK_UP)&0x8000)
		{
			if (y > 0)
				y--;
		}
		if (GetAsyncKeyState(VK_DOWN)&0x8000)
		{
			if (y < 24)
				y++;
		}
		if (GetAsyncKeyState(VK_LEFT)&0x8000)
		{
			if (x > 0)
				x--;
		}
		if (GetAsyncKeyState(VK_RIGHT)&0x8000)
		{
			if (x < 79)
				x++;
		}
		Sleep(100);		// Sleep() 함수를 사용하지 않으면 키가 너무 빠르게 입력 된다.
	}
	return 0;
}