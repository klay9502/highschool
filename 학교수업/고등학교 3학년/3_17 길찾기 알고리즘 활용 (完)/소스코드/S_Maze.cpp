#include "stdafx.h"
#include "S_Maze.h"
#include "O_Wall.h"
#include "O_Box.h"

bool onlyone = true;

int i;

int maze[MAZE_ROWS + 2][MAZE_COLS + 2] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1,
	1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1,
	1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1,
	1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1,
	1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1,
	1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1,
	1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

int mark[MAZE_ROWS + 2][MAZE_COLS + 2] = { 0, };	// 중복 선택 방지

S_Maze::S_Maze(void)
{
	// 방향 초기화
	move[0].vert = -1; move[0].horiz = 0;	// N
	move[1].vert = -1; move[1].horiz = 1;	// NE
	move[2].vert = 0; move[2].horiz = 1;	// E
	move[3].vert = 1; move[3].horiz = 1;	// SE
	move[4].vert = 1; move[4].horiz = 0;	// S
	move[5].vert = 1; move[5].horiz = -1;	// SW
	move[6].vert = 0; move[6].horiz = -1;	// W
	move[7].vert = -1; move[7].horiz = -1;	// NW

	stack_top = -1;
}

S_Maze::~S_Maze(void)
{
	// empty...
}

void S_Maze::Init(void)
{
	for (int i = 0; i < MAZE_ROWS + 2; i++)
	{
		for (int j = 0; j < MAZE_COLS + 2; j++)
		{
			m_objWall[j][i] = new O_Wall();
			m_objWall[j][i]->Init();
			m_objWall[j][i]->SetPosition((50 * i) + 25, (50 * j) + 25);
			m_objWall[j][i]->Active = maze[j][i];
		}
	}

	m_objBox = new O_Box();
	m_objBox->Init();
	m_objBox->SetPosition(75, 75);
}

void S_Maze::Process(void)
{
	if (stack_top == -1)
	{
		path();
	}

	if (onlyone)
	{
		for (; i <= stack_top;)
		{
			switch (stack[i].dir)
			{
			case 0:
				m_objBox->SetPosition(m_objBox->GetPosition().x, m_objBox->GetPosition().y - 50);
				i++; return;
			case 1:
				m_objBox->SetPosition(m_objBox->GetPosition().x + 50, m_objBox->GetPosition().y - 50);
				i++; return;
			case 2:
				m_objBox->SetPosition(m_objBox->GetPosition().x + 50, m_objBox->GetPosition().y);
				i++; return;
			case 3:
				m_objBox->SetPosition(m_objBox->GetPosition().x + 50, m_objBox->GetPosition().y + 50);
				i++; return;
			case 4:
				m_objBox->SetPosition(m_objBox->GetPosition().x, m_objBox->GetPosition().y + 50);
				i++; return;
			case 5:
				m_objBox->SetPosition(m_objBox->GetPosition().x - 50, m_objBox->GetPosition().y + 50);
				i++; return;
			case 6:
				m_objBox->SetPosition(m_objBox->GetPosition().x - 50, m_objBox->GetPosition().y);
				i++; return;
			case 7:
				m_objBox->SetPosition(m_objBox->GetPosition().x - 50, m_objBox->GetPosition().y - 50);
				i++; return;
			}
		}
		onlyone = false;
	}
}

void S_Maze::Render(void)
{
	for (int i = 0; i < MAZE_ROWS + 2; i++)
	{
		for (int j = 0; j < MAZE_COLS + 2; j++)
		{
			if (m_objWall[j][i]->Active == 1)
			{
				m_objWall[j][i]->Render();
			}
		}
	}
	_sleep(100);
	m_objBox->Render();
}

void S_Maze::Release(void)
{
	for (int i = 0; i < MAZE_ROWS + 2; i++)
	{
		for (int j = 0; j < MAZE_COLS + 2; j++)
		{
			m_objWall[i][j]->Release();
		}
	}

	m_objBox->Release();
}

void S_Maze::path(void)
{
	int row, col, next_row, next_col, dir, found = false;

	mark[1][1] = 1; stack_top = 0;
	stack[0].row = 1; stack[0].col = 1; stack[0].dir = 2;

	ELEMENT position;

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

		for (int i = 0; i <= stack_top; i++)
		{
			maze[stack[i].row][stack[i].col] = stack[i].dir + 10;
		}

		maze[EXIT_ROW][EXIT_COL] = 99;

		if (found)
		{;
			printf("The path is :\n");

			for (int i = 0; i <= stack_top; i++)
			{
				printf("(%2d, %2d, %2d)->\n", stack[i].row, stack[i].col, stack[i].dir);
			}

			printf("(%2d, %2d)\n", EXIT_ROW, EXIT_COL);
		}
	}
}

void S_Maze::stack_add(int* top, ELEMENT* new_element)
{
	if (*top >= MAX_STACK_SIZE - 1)
	{
		printf("stack full!\n");
		exit(1);
	}

	memcpy(&stack[++(*top)], new_element, sizeof(ELEMENT));
}

ELEMENT* S_Maze::stack_delete(int* top)
{
	if (*top == -1)
	{
		printf("stack empty\n");
		exit(1);
	}

	return &stack[(*top)--];
}

void S_Maze::draw_maze(void)
{
	for (int i = 0; i <= stack_top; i++)
	{
		maze[stack[i].row][stack[i].col] = stack[i].dir + 10;
	}

	/*for (int i = 0; i < MAZE_ROWS + 2; i++)
	{
		for (int j = 0; j < MAZE_COLS + 2; j++)
		{
			switch (maze[i][j])
			{
			case 0:
				break;
			case 1:
				m_objWall[i][j]->Render();
				break;
			case 10:
				printf("↑");
				m_objBox->SetPosition(m_objBox->GetPosition().x, m_objBox->GetPosition().y - 50);
				break;
			case 11:
				printf("↗");
				m_objBox->SetPosition(m_objBox->GetPosition().x + 50, m_objBox->GetPosition().y - 50);
				break;
			case 12:
				printf("→");
				m_objBox->SetPosition(m_objBox->GetPosition().x + 50, m_objBox->GetPosition().y);
				break;
			case 13:
				printf("↘");
				m_objBox->SetPosition(m_objBox->GetPosition().x + 50, m_objBox->GetPosition().y + 50);
				break;
			case 14:
				printf("↓");
				m_objBox->SetPosition(m_objBox->GetPosition().x, m_objBox->GetPosition().y + 50);
				break;
			case 15:
				printf("↙");
				m_objBox->SetPosition(m_objBox->GetPosition().x - 50, m_objBox->GetPosition().y + 50);
				break;
			case 16:
				printf("←");
				m_objBox->SetPosition(m_objBox->GetPosition().x - 50, m_objBox->GetPosition().y);
				break;
			case 17:
				printf("↖");
				m_objBox->SetPosition(m_objBox->GetPosition().x - 50, m_objBox->GetPosition().y - 50);
				break;
			case 98:
				printf("◆");
				break;
			case 99:
				printf("♣");
				break;
			}
		}
	}*/
}