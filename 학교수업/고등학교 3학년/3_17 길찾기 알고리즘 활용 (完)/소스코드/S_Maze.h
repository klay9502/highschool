#pragma once
#include "Scene.h"

#define MAZE_ROWS 10
#define MAZE_COLS 10

#define MAX_STACK_SIZE 2048

#define EXIT_ROW MAZE_ROWS
#define EXIT_COL MAZE_COLS

class CSprite;
class O_Wall;
class O_Box;

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

class S_Maze :
	public CScene
{
public:
	O_Wall* m_objWall[MAZE_ROWS + 2][MAZE_COLS + 2];
	O_Box* m_objBox;
	OFFSETS move[8];
	int stack_top;
	void draw_maze(void);

	ELEMENT stack[MAX_STACK_SIZE];	// 스텍 선언

	ELEMENT* stack_delete(int* top);
	void stack_add(int* top, ELEMENT* new_element);
public:
	S_Maze(void);
	~S_Maze(void);

	void Init(void) override;
	void Process(void) override;
	void Render(void) override;
	void Release(void) override;

	void path(void);
};

