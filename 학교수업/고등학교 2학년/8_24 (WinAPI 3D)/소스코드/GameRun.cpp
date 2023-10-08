#include "stdafx.h"

extern HDC hdc;

extern int nFPS;
extern int nCount;

extern MESH gTetra;
extern RECT rtScreen;

void Run(void)
{
	FPSOutput();

	int w = (rtScreen.right - rtScreen.left) / 2;
	int h = (rtScreen.bottom - rtScreen.top) / 2;

	DrawBigDot(gTetra.pVertexList[0].x + w, gTetra.pVertexList[0].y + h, yellow);
	DrawBigDot(gTetra.pVertexList[1].x + w, gTetra.pVertexList[1].y + h, yellow);
	DrawBigDot(gTetra.pVertexList[2].x + w, gTetra.pVertexList[2].y + h, yellow);
	DrawBigDot(gTetra.pVertexList[3].x + w, gTetra.pVertexList[3].y + h, yellow);

	YellowPen();

	for (int i = 0; i < 3; i++)
	{
		Line(gTetra.pVertexList[gTetra.pVertexIndexList[i]].x + w,
			gTetra.pVertexList[gTetra.pVertexIndexList[i]].y + h,
			gTetra.pVertexList[gTetra.pVertexIndexList[i + 1]].x + w,
			gTetra.pVertexList[gTetra.pVertexIndexList[i + 1]].y + h);

		Line(gTetra.pVertexList[gTetra.pVertexIndexList[i + 1]].x + w,
			gTetra.pVertexList[gTetra.pVertexIndexList[i + 1]].y + h,
			gTetra.pVertexList[gTetra.pVertexIndexList[i + 2]].x + w,
			gTetra.pVertexList[gTetra.pVertexIndexList[i + 2]].y + h);

		Line(gTetra.pVertexList[gTetra.pVertexIndexList[i + 2]].x + w,
			gTetra.pVertexList[gTetra.pVertexIndexList[i + 2]].y + h,
			gTetra.pVertexList[gTetra.pVertexIndexList[i]].x + w,
			gTetra.pVertexList[gTetra.pVertexIndexList[i]].y + h);
	}
}

void FPSOutput(void)
{
	char strTemp[128];
	sprintf(strTemp, "[FPS = %3d]", nFPS);
	TextOut(hdc, 0, 0, strTemp, strlen(strTemp));
}