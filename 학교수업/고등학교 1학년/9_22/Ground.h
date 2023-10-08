#pragma once

typedef struct tagGround
{
	int y;
	char* ch;
}Ground;

Ground* InitGround();

void DrawGround(Ground* gr);

void ReleaseGround(Ground* gr);