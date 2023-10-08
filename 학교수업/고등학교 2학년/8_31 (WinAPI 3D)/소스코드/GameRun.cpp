#include "stdafx.h"

extern RECT	rtScreen;
extern int	nFPS;
extern int	nCount;

extern MESH		gTetra;
extern MESH		gSTetra;

extern MESH		gHexahedron;
extern MESH		gSHexahedron;

void YellowDot(int x, int y)
{
	DrawDot(x + 0, y + 0, RGB(255, 255, 0));

	DrawDot(x + 0, y + 1, RGB(255, 255, 0));
	DrawDot(x + 1, y + 0, RGB(255, 255, 0));
	DrawDot(x + 1, y + 1, RGB(255, 255, 0));

	DrawDot(x + 0, y - 1, RGB(255, 255, 0));
	DrawDot(x + 1, y - 0, RGB(255, 255, 0));
	DrawDot(x + 1, y - 1, RGB(255, 255, 0));

	DrawDot(x - 0, y + 1, RGB(255, 255, 0));
	DrawDot(x - 1, y + 0, RGB(255, 255, 0));
	DrawDot(x - 1, y + 1, RGB(255, 255, 0));

	DrawDot(x - 0, y - 1, RGB(255, 255, 0));
	DrawDot(x - 1, y - 0, RGB(255, 255, 0));
	DrawDot(x - 1, y - 1, RGB(255, 255, 0));
}

void BigDot(int x, int y, int color)
{
	DrawDot(x + 0, y + 0, color);

	DrawDot(x + 0, y + 1, color);
	DrawDot(x + 1, y + 0, color);
	DrawDot(x + 1, y + 1, color);

	DrawDot(x + 0, y - 1, color);
	DrawDot(x + 1, y - 0, color);
	DrawDot(x + 1, y - 1, color);

	DrawDot(x - 0, y + 1, color);
	DrawDot(x - 1, y + 0, color);
	DrawDot(x - 1, y + 1, color);

	DrawDot(x - 0, y - 1, color);
	DrawDot(x - 1, y - 0, color);
	DrawDot(x - 1, y - 1, color);
}

void Cross()
{
	POINT ptMid;
	ptMid.x = (rtScreen.right - rtScreen.left) / 2;
	ptMid.y = (rtScreen.bottom - rtScreen.top) / 2;

	WhitePen();
	Line(ptMid.x, rtScreen.top, ptMid.x, rtScreen.bottom);
	Line(rtScreen.left, ptMid.y, rtScreen.right, ptMid.y);
}

void Cross(int x, int y)
{
	if (x == 0) x = (rtScreen.right - rtScreen.left) / 2;
	if (y == 0) y = (rtScreen.bottom - rtScreen.top) / 2;

	WhitePen();
	Line(x, rtScreen.top, x, rtScreen.bottom);
	Line(rtScreen.left, y, rtScreen.right, y);

	int c = 0;
	int k = 5;
	for (int i = x, j = x; i < rtScreen.right; i += 10, j -= 10)
	{
		YellowPen();
		if (!(c % 5))
		{
			WhitePen();
			k = 10;
			char str[8];
			sprintf(str, "%d", i - x);
			TransparentText();
			TextColor(yellow);
			TextAtPos(i, y + 20, str);
			TextAtPos(j, y + 20, str);
		}
		else k = 5;
		Line(i, y + k, i, y - k);
		Line(j, y + k, j, y - k);
		c++;
	}

	for (int i = y, j = y; i < rtScreen.bottom; i += 10, j -= 10)
	{
		YellowPen();
		if (!(c % 5))
		{
			WhitePen();
			k = 10;
			char str[8];
			sprintf(str, "%d", i - (rtScreen.bottom / 2));
			TransparentText();
			TextColor(cyan);
			TextAtPos(x - 20, i - 4, str);
			TextAtPos(x - 20, j - 4, str);
		}
		else k = 5;
		Line(x + k, i, x - k, i);
		Line(x + k, j, x - k, j);
		c++;
	}
}

void Grid()
{
	int c = 0;
	for (int i = rtScreen.left; i <= rtScreen.right; i += 10)
	{
		GrayPen();
		if (!(c % 5))	WhitePen();
		Line(i, rtScreen.top, i, rtScreen.bottom);
		c++;
	}
	c = 0;
	for (int j = rtScreen.top; j <= rtScreen.bottom; j += 10)
	{
		GrayPen();
		if (!(c % 5))	WhitePen();
		Line(rtScreen.left, j, rtScreen.right, j);
		c++;
	}
}

void OutputFPS()
{
	char strTemp[128];
	sprintf(strTemp, "[FPS = %3d]", nFPS);
	TextColor(cyan);
	TransparentText();
	TextAtPos(0, 0, strTemp);
	nCount++;
}

//==============================
// 게임 루프
void Run()
{
	MATRIX CTM, RXM, RYM, RZM, TTM;
	CTM = Identity();
	Cross();

	int w = (rtScreen.right - rtScreen.left) / 2;
	int h = (rtScreen.bottom - rtScreen.top) / 2;

	static int theta;
	if (theta > 360) theta = 0;

	RXM = RotateX(theta);
	RYM = RotateY(theta);
	RZM = RotateZ(theta);

	TTM = Translate(w, h, 0);	// 중심이동

	CTM = Multiply(RXM, RYM);
	CTM = Multiply(CTM, RZM);
	CTM = Multiply(CTM, TTM);

	//for (int i = 0; i < gTetra.numVertex; i++)
	//{
	//	gSTetra.pVertexList[i] = Transform(gTetra.pVertexList[i], CTM);
	//}

	//YellowDot(gSTetra.pVertexList[0].x+w, gSTetra.pVertexList[0].y+h);
	//YellowDot(gSTetra.pVertexList[1].x+w, gSTetra.pVertexList[1].y+h);
	//YellowDot(gSTetra.pVertexList[2].x+w, gSTetra.pVertexList[2].y+h);
	//YellowDot(gSTetra.pVertexList[3].x+w, gSTetra.pVertexList[3].y+h);

	//for (int i = 0; i < gTetra.numTriangle; i++)
	//{
	//	Line(	gSTetra.pVertexList[gSTetra.pVertexIndexList[i]].x + w, 
	//			gSTetra.pVertexList[gSTetra.pVertexIndexList[i]].y + h,
	//			gSTetra.pVertexList[gSTetra.pVertexIndexList[i+1]].x + w, 
	//			gSTetra.pVertexList[gSTetra.pVertexIndexList[i+1]].y + h);
	//	Line(	gSTetra.pVertexList[gSTetra.pVertexIndexList[i+1]].x + w,
	//			gSTetra.pVertexList[gSTetra.pVertexIndexList[i+1]].y + h,
	//			gSTetra.pVertexList[gSTetra.pVertexIndexList[i+2]].x + w,
	//			gSTetra.pVertexList[gSTetra.pVertexIndexList[i+2]].y + h);
	//	Line(	gSTetra.pVertexList[gSTetra.pVertexIndexList[i+2]].x + w,
	//			gSTetra.pVertexList[gSTetra.pVertexIndexList[i+2]].y + h,
	//			gSTetra.pVertexList[gSTetra.pVertexIndexList[i]].x + w,
	//			gSTetra.pVertexList[gSTetra.pVertexIndexList[i]].y + h);
	//}

	for (int i = 0; i < gHexahedron.numVertex; i++)
	{
		gSHexahedron.pVertexList[i] = Transform(gHexahedron.pVertexList[i], CTM);
	}

	YellowDot(gSHexahedron.pVertexList[0].x + w, gSHexahedron.pVertexList[0].y + h);
	YellowDot(gSHexahedron.pVertexList[1].x + w, gSHexahedron.pVertexList[1].y + h);
	YellowDot(gSHexahedron.pVertexList[2].x + w, gSHexahedron.pVertexList[2].y + h);
	YellowDot(gSHexahedron.pVertexList[3].x + w, gSHexahedron.pVertexList[3].y + h);
	YellowDot(gSHexahedron.pVertexList[4].x + w, gSHexahedron.pVertexList[4].y + h);
	YellowDot(gSHexahedron.pVertexList[5].x + w, gSHexahedron.pVertexList[5].y + h);
	YellowDot(gSHexahedron.pVertexList[6].x + w, gSHexahedron.pVertexList[6].y + h);
	YellowDot(gSHexahedron.pVertexList[7].x + w, gSHexahedron.pVertexList[7].y + h);

	for (int i = 0; i < gHexahedron.numTriangle * 3; i += 3)
	{
		Line(gSHexahedron.pVertexList[gSHexahedron.pVertexIndexList[i]].x + w,
			gSHexahedron.pVertexList[gSHexahedron.pVertexIndexList[i]].y + h,
			gSHexahedron.pVertexList[gSHexahedron.pVertexIndexList[i + 1]].x + w,
			gSHexahedron.pVertexList[gSHexahedron.pVertexIndexList[i + 1]].y + h);
		Line(gSHexahedron.pVertexList[gSHexahedron.pVertexIndexList[i + 1]].x + w,
			gSHexahedron.pVertexList[gSHexahedron.pVertexIndexList[i + 1]].y + h,
			gSHexahedron.pVertexList[gSHexahedron.pVertexIndexList[i + 2]].x + w,
			gSHexahedron.pVertexList[gSHexahedron.pVertexIndexList[i + 2]].y + h);
		Line(gSHexahedron.pVertexList[gSHexahedron.pVertexIndexList[i + 2]].x + w,
			gSHexahedron.pVertexList[gSHexahedron.pVertexIndexList[i + 2]].y + h,
			gSHexahedron.pVertexList[gSHexahedron.pVertexIndexList[i]].x + w,
			gSHexahedron.pVertexList[gSHexahedron.pVertexIndexList[i]].y + h);
	}

	OutputFPS();
	theta = 15;
}