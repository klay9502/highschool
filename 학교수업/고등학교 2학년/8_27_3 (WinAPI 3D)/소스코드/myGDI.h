#pragma once

enum	{ red, blue, green, black, white, gray, pink, yellow, 
	  orange, purple, brown, dkgreen, cyan, ltgray, ltpink};

void InitGDI();
void ReleaseGDI();
void StartDraw(HDC hDC);
void StopDraw();
void DrawDot(int x, int y, COLORREF color);
void DrawDot(int x, int y, int color);
void Line(int x1, int y1, int x2, int y2);
void Rect(int x1, int y1, int x2, int y2);
void R_Rect(int x1, int y1, int x2, int y2, int w, int h);
void Circle(int x1, int y1, int x2, int y2);
void Circle(int x, int y, int r);
void Poly(POINT pPt[], int n);
void TextAtPos(int x, int y, TCHAR* string);
void TransparentText();
void OpaqueText();
void TextColor(int color);
void TextColor(int r, int g, int b);

void BlackPen();
void WhitePen();
void RedPen();
void GreenPen();
void BluePen();
void GrayPen();
void PinkPen();
void YellowPen();
void OrangePen();
void PurplePen();
void BrownPen();

void DarkGreenPen();
void LightGrayPen();
void LightPinkPen();

void BlackBrush();
void WhiteBrush();
void HollowBrush();
void GreenBrush();
void RedBrush();
void BlueBrush();
void GrayBrush();
void BrownBrush();
void YellowBrush();
void DarkGreenBrush();
void OrangeBrush();