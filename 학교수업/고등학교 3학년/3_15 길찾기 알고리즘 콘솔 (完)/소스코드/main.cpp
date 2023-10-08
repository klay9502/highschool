#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Color.h"

#define MAX_STACK_SIZE 2048

#define MAZE_ROWS 12
#define MAZE_COLS 15

int EXIT_ROW = 0;
int EXIT_COL = 0;
int START_ROW = 0;
int START_COL = 0;

typedef struct tag0ffsets
{
	int vert;
	int horiz;
} OFFSETS;

typedef struct tagElement
{
	int row;
	int col;
	int dir;
} ELEMENT;

OFFSETS move[8];

int maze[MAZE_ROWS + 2][MAZE_COLS + 2] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1,
	1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1,
	1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
	1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1,
	1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1,
	1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1,
	1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1,
	1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1,
	1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1,
	1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

int stack_top;

int mark[MAZE_ROWS + 2][MAZE_COLS + 2] = { 0, };	// 중복 선택 방지

ELEMENT stack[MAX_STACK_SIZE];	// 스텍 선언

void stack_add(int* top, ELEMENT* new_element);
ELEMENT* stack_delete(int* top);
void make(void);
void path(void);
void draw_maze(void);

void gotoxy(int x, int y)
{
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(COL, CursorPosition);
}

void stack_add(int* top, ELEMENT* new_element)
{
	if (*top >= MAX_STACK_SIZE - 1)
	{
		printf("stack full!\n");
		exit(1);
	}

	memcpy(&stack[++(*top)], new_element, sizeof(ELEMENT));
}

ELEMENT* stack_delete(int* top)
{
	if (*top == -1)
	{
		printf("stack empty\n");
		exit(1);
	}

	return &stack[(*top)--];
}

int main(void)
{
	// 방향 초기화
	move[0].vert = -1; move[0].horiz =	0;	// N
	move[1].vert = -1; move[1].horiz =	1;	// NE
	move[2].vert =	0; move[2].horiz =	1;	// E
	move[3].vert =	1; move[3].horiz =	1;	// SE
	move[4].vert =	1; move[4].horiz =	0;	// S
	move[5].vert =	1; move[5].horiz = -1;	// SW
	move[6].vert =	0; move[6].horiz = -1;	// W
	move[7].vert = -1; move[7].horiz = -1;	// NW

	stack_top = -1;

	make();
	path();

	return 0;
}

void make(void)
{
	int wid = 2, hei = 1;
	int maze_wid = 1, maze_hei = 1;
	int edit_code = 1;
	draw_maze();

	while (1)
	{
		///////////////////////////////////////////////////
		// 방향키 입력
		///////////////////////////////////////////////////

		if (GetAsyncKeyState(VK_RIGHT) &1)
		{
			wid += 2;
			maze_wid += 1;

			if (wid / 2 >=  MAZE_COLS + 1)
			{
				wid -= 2;
				maze_wid -= 1;
			}

			system("cls");
			draw_maze();
		}

		if (GetAsyncKeyState(VK_LEFT) & 1)
		{
			wid -= 2;
			maze_wid -= 1;

			if (wid / 2 <= 0)
			{
				wid += 2;
				maze_wid += 1;
			}

			system("cls");
			draw_maze();
		}

		if (GetAsyncKeyState(VK_UP) & 1)
		{
			hei -= 1;
			maze_hei -= 1;

			if (hei <= 0)
			{
				hei += 1;
				maze_hei += 1;
			}

			system("cls");
			draw_maze();
		}

		if (GetAsyncKeyState(VK_DOWN) & 1)
		{
			hei += 1;
			maze_hei += 1;

			if (hei >= MAZE_ROWS + 1)
			{
				hei -= 1;
				maze_hei -= 1;
			}

			system("cls");
			draw_maze();
		}

		///////////////////////////////////////////////////

		///////////////////////////////////////////////////
		// 숫자키 입력
		///////////////////////////////////////////////////
		if (GetAsyncKeyState(VK_NUMPAD1) & 1)
		{
			edit_code = 1;
		}

		if (GetAsyncKeyState(VK_NUMPAD2) & 1)
		{
			edit_code = 2;
		}

		if (GetAsyncKeyState(VK_NUMPAD3) & 1)
		{
			edit_code = 3;
		}

		if (GetAsyncKeyState(VK_NUMPAD4) & 1)
		{
			edit_code = 4;
		}
		///////////////////////////////////////////////////

		if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");
			return;
		}

		gotoxy(wid, hei);

		switch (edit_code)
		{
		case 1:
			GREEN printf("■");
			break;
		case 2:
			GREEN printf("□");
			break;
		case 3:
			GREEN printf("◆");
			break;
		case 4:
			GREEN printf("♣");
			break;
		}

		if (GetAsyncKeyState(VK_SPACE))
		{
			switch (edit_code)
			{
			case 1:
				maze[maze_hei][maze_wid] = 1;
				break;
			case 2:
				maze[maze_hei][maze_wid] = 0;
				break;
			case 3:
				maze[START_ROW][START_COL] = 1;
				maze[maze_hei][maze_wid] = 98;
				START_ROW = maze_hei;
				START_COL = maze_wid;
				break;
			case 4:
				maze[EXIT_ROW][EXIT_COL] = 1;
				maze[maze_hei][maze_wid] = 99;
				EXIT_ROW = maze_hei;
				EXIT_COL = maze_wid;
				break;
			}
		}
	}
}

void path(void)
{
	int row, col, next_row, next_col, dir, found = false;

	ELEMENT position;

	mark[1][1] = 1; stack_top = 0;
	stack[0].row = START_ROW; stack[0].col = START_COL; stack[0].dir = 2;

	if (START_ROW == 0 || START_COL == 0 || EXIT_ROW == 0 || EXIT_COL == 0)
	{
		WHITE printf("****************ERROR**************\n");
		printf("*                                 *\n");
		printf("* START Position or EXIT Position *\n");
		printf("*      do not have Positions      *\n");
		printf("*                                 *\n");
		printf("***********************************\n");
		system("PAUSE");
		return;
	}

	while (stack_top > -1 && !found)
	{
		memcpy(&position, stack_delete(&stack_top), sizeof(ELEMENT));
		row = position.row; col = position.col; dir = position.dir;

		while (dir < 8 && !found)
		{
			next_row = row + move[dir].vert;
			next_col = col + move[dir].horiz;

			if (next_row == EXIT_ROW && next_col == EXIT_COL)
			{
				position.row = row; position.col = col; position.dir = dir;
				stack_add(&stack_top, &position);
				found = true;
			}
			else if (!maze[next_row][next_col] && !mark[next_row][next_col])
			{
				mark[next_row][next_col] = 1;
				position.row = row; position.col = col; position.dir = dir;
				stack_add(&stack_top, &position);
				row = next_row; col = next_col; dir = 0;
			}
			else
			{
				++dir;
			}
			// draw_maze();
			// system("cls");
		}
	}

	if (found)
	{
		draw_maze();
		printf("The path is :\n");

		for (int i = 0; i <= stack_top; i++)
		{
			printf("(%2d, %2d)->\n", stack[i].row, stack[i].col);
		}

		printf("(%2d, %2d)\n", EXIT_ROW, EXIT_COL);
		system("PAUSE");
	}
	else
	{
		WHITE printf("***************ERROR*************\n");
		printf("*                               *\n");
		printf("* The maze does not have a path *\n");
		printf("*                               *\n");
		printf("*********************************\n");
		system("PAUSE");
	}
}

void draw_maze(void)
{
	for (int i = 0; i <= stack_top; i++)
	{
		maze[stack[i].row][stack[i].col] = stack[i].dir + 10;
	}

	// maze[EXIT_ROW][EXIT_COL] = 99;

	for (int i = 0; i < MAZE_ROWS + 2; i++)
	{
		for (int j = 0; j < MAZE_COLS + 2; j++)
		{
			switch (maze[i][j])
			{
			case 0:
				GRAY printf("□");
				break;
			case 1:
				WHITE printf("■");
				break;
			case 10:
				YELLOW printf("↑");
				break;
			case 11:
				YELLOW printf("↗");
				break;
			case 12:
				YELLOW printf("→");
				break;
			case 13:
				YELLOW printf("↘");
				break;
			case 14:
				YELLOW printf("↓");
				break;
			case 15:
				YELLOW printf("↙");
				break;
			case 16:
				YELLOW printf("←");
				break;
			case 17:
				YELLOW printf("↖");
				break;
			case 98:
				PLUM printf("◆");
				break;
			case 99:
				SKY printf("♣");
				break;
			}
		}
		printf("\n");
	}
	//_sleep(150);
}