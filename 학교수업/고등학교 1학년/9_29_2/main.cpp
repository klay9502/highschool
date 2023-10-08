#include "Turboc.h"

#define FALSE	0
#define TRUE	1

#define RIGHT	77
#define LEFT	75
#define UP		72
#define DOWN	80
#define ESC		27

#define MAX		1024

typedef struct Signal {
	int exist;		// ���翩��
	char ch;		// ����� ����
	int x, y;		// ��ǥ��
	int distance;	// �̵��� �Ÿ�
	int nFrame;		// �̵��ӵ�
	int nStay;
}Signal;

Signal S[MAX];

int main(void)
{
	int ch;
	int frame = 200;	// �ӵ�
	int freq = 15;		// ��

	clrscr();
	setcursortype( NOCURSOR );
	randomize();

	while(1)
	{
		gotoxy(0, 23);
		printf("��Ʈ���� �䳻����, ����:�ӵ� ����, �¿�:�� ����, ESC:����, �ӵ�:%d, ��:%d  ", frame, freq);

		if (kbhit())
		{
			ch =getch();

			if (ch==0xE0 || ch == 0)	// �����¿� ��������
			{
				ch = getch();
				
				switch (ch)
				{
				case UP:
					if (frame < 1000)
						frame += 10;
					else
						frame = 1000;
					break;
				case DOWN:
					if (frame > 10)
						frame -= 10;
					else
						frame = 10;
					break;
				case RIGHT:
					if (freq > 1)
						freq -= 1;
					else
						freq = 1;
					break;
				case LEFT:
					if (freq < 30)
						freq += 1;
					else
						freq = 30;
					break;
				}
			}

			else if (ch == ESC)
			{
				exit(0);
			}
		}

		if (random(freq) == 0)
		{
			for (int i = 0; i < MAX; i++)
			{
				if(S[i].exist == FALSE)
				{
					S[i].exist = TRUE;
					S[i].ch = random('Z' - 'A' + 1) + 'A';
					S[i].x = random(80);
					S[i].y = 0;
					S[i].distance = random(14) + 9;		// 9 ~ 22
					S[i].nFrame = S[i].nStay = random(15) + 5;
					break;
				}
			}
		}
		for (int i = 0; i < MAX; i++)
		{
			if (S[i].exist == TRUE)
			{
				S[i].nStay--;

				if (S[i].nStay == 0)
				{
					S[i].nStay = S[i].nFrame;
					gotoxy(S[i].x, S[i].y);
					putch(' ');
					S[i].y++;

					if (S[i].y < S[i].distance)
					{
						gotoxy(S[i].x, S[i].y);
						putch(S[i].ch);
					}
					else
					{
						S[i].exist = FALSE;
					}
				}
			}
		}
			delay(1000/frame);
	}
	return 0;
}