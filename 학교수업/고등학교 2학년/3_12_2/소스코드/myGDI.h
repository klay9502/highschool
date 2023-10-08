#pragma once

enum { red, blue, green, black, white, gray, pink, yellow,
	orange, purple, brown, dkgreen, cyan, ltgray, ltpink};

void InitGDI(void);
void StartDraw(HDC hDC);
void StopDraw(void);
void DrawnDot(int x, int y, COLORREF color);
void Line(int x1, int y1, int x2, int y2);
void Rect(int x1, int y1, int x2, int y2);
void R_Rect(int x1, int y1, int x2, int y2, int w, int h);
void Circle(int x1, int y1, int x2, int y2);
void Circle(int x, int y, int r);
void Ploy(POINT pPT[], int n);
void TextAtPos(int x, int y, const std::string &s);
void TransparentText(void);
void OpaqueText(void);
void TextColor(int r, int g, int b);
void ReleaseGDI(void);

void RedPen();
void BluePen(); 
void GreenPen();
void BlackPen();
void WhilePen();
void GrayPen();
void PinkPen(); 
void YellowPen();
void OrangePen();
void PurplePen();
void BrownPen();
void DarkGreenPen();
void CyanPen();
void LightGrayPen();
void LightPinkPen();

void BlackBrush();
void WhiteBrush();	 
void HollowBrush();
void GreenBrush();
void RedBrush();
void BlueBrush();
void GrayBrush();
void PinkBrush();	 
void YellowBrush();
void OrangeBrush();
void PurpleBrush();
void BrownBrush();
void DarkGreenBrush();
void CyanBrush();
void LightGrayBrush();
void LightPinkBrush();