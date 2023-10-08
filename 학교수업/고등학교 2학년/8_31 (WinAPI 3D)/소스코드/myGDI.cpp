#include "stdafx.h"

const int NumColors = 15;
const COLORREF colors[NumColors] = { RGB(255,0,0), //Red
								   RGB(0,0,255), //Blue
								   RGB(0,255,0), //Green
								   RGB(0,0,0), //Black
								   RGB(255,255,255), //White
								   RGB(150,150,150), //Gray
								   RGB(255,200,200), //Pink
								   RGB(255,255,0), //Yellow
								   RGB(255,170,0), //Orange
								   RGB(255,0,255), //Purple
								   RGB(133,90,0), //Brown
								   RGB(0,100,0), //Dark Green
								   RGB(0,255,255), //Cyan
								   RGB(200,200,200),//Light Gray
								   RGB(255,230,230), //Light Pink
};

HDC		hdc;

HPEN hOldPen;
HPEN hRedPen;	
HPEN hBluePen;	
HPEN hGreenPen;
HPEN hBlackPen;	
HPEN hWhitePen;	
HPEN hGrayPen;	
HPEN hPinkPen;
HPEN hYellowPen;	
HPEN hOrangePen;
HPEN hPurplePen;	
HPEN hBrownPen;
HPEN hDkGreenPen;
HPEN hCyanPen;	
HPEN hLtGrayPen;
HPEN hLtPinkPen;

HBRUSH hOldBrush;
HBRUSH hRedBrush;	
HBRUSH hBlueBrush;
HBRUSH hGreenBrush;	
HBRUSH hBlackBrush;	
HBRUSH hWhiteBrush;
HBRUSH hGrayBrush;	
HBRUSH hPinkBrush;	
HBRUSH hYellowBrush;
HBRUSH hOrangeBrush;	
HBRUSH hPurpleBrush;	
HBRUSH hBrownBrush;
HBRUSH hDkGreenBrush;		
HBRUSH hCyanBrush;	
HBRUSH hLtGrayBrush;			
HBRUSH hLtPinkBrush;

void InitGDI()
{
	hRedPen		=	CreatePen(PS_SOLID, 1, colors[red]);
	hBluePen		=	CreatePen(PS_SOLID, 1, colors[blue]);
	hGreenPen	=	CreatePen(PS_SOLID, 1, colors[green]);
	hBlackPen	=	CreatePen(PS_SOLID, 1, colors[black]);
	hWhitePen	=	CreatePen(PS_SOLID, 1, colors[white]);
	hGrayPen		=	CreatePen(PS_SOLID, 1, colors[gray]);
	hPinkPen		=	CreatePen(PS_SOLID, 1, colors[pink]);
	hYellowPen	=	CreatePen(PS_SOLID, 1, colors[yellow]);
	hOrangePen	=	CreatePen(PS_SOLID, 1, colors[orange]);
	hPurplePen	=	CreatePen(PS_SOLID, 1, colors[purple]);
	hBrownPen	=	CreatePen(PS_SOLID, 1, colors[brown]);
	hDkGreenPen	=	CreatePen(PS_SOLID, 1, colors[dkgreen]);
	hCyanPen		=	CreatePen(PS_SOLID, 1, colors[cyan]);
	hLtGrayPen	=	CreatePen(PS_SOLID, 1, colors[ltgray]);
	hLtPinkPen	=	CreatePen(PS_SOLID, 1, colors[ltpink]);

	hRedBrush	=	CreateSolidBrush(colors[red]);
	hBlueBrush	=	CreateSolidBrush(colors[blue]);
	hGreenBrush	=	CreateSolidBrush(colors[green]);
	hBlackBrush	=	CreateSolidBrush(colors[black]);
	hWhiteBrush	=	CreateSolidBrush(colors[white]);
	hGrayBrush	=	CreateSolidBrush(colors[gray]);
	hPinkBrush	=	CreateSolidBrush(colors[pink]);
	hYellowBrush =	CreateSolidBrush(colors[yellow]);
	hOrangeBrush =	CreateSolidBrush(colors[orange]);
	hPurpleBrush =	CreateSolidBrush(colors[purple]);
	hBrownBrush	=	CreateSolidBrush(colors[brown]);
	hDkGreenBrush=	CreateSolidBrush(colors[dkgreen]);
	hCyanBrush	=	CreateSolidBrush(colors[cyan]);
	hLtGrayBrush =	CreateSolidBrush(colors[ltgray]);
	hLtPinkBrush =	CreateSolidBrush(colors[ltpink]);
}

void ReleaseGDI()
{
	DeleteObject(hRedPen);
	DeleteObject(hBluePen);	
	DeleteObject(hGreenPen);	
	DeleteObject(hBlackPen);	
	DeleteObject(hWhitePen);	
	DeleteObject(hGrayPen);	
	DeleteObject(hPinkPen);	
	DeleteObject(hYellowPen);	
	DeleteObject(hOrangePen);	
	DeleteObject(hPurplePen);	
	DeleteObject(hBrownPen);	
	DeleteObject(hDkGreenPen); 
	DeleteObject(hCyanPen);	
	DeleteObject(hLtGrayPen);	
	DeleteObject(hLtPinkPen);	

	DeleteObject(hRedBrush);
	DeleteObject(hBlueBrush);	
	DeleteObject(hGreenBrush);	
	DeleteObject(hBlackBrush);	
	DeleteObject(hWhiteBrush);	
	DeleteObject(hGrayBrush);	
	DeleteObject(hPinkBrush);	
	DeleteObject(hYellowBrush);	
	DeleteObject(hOrangeBrush);	
	DeleteObject(hPurpleBrush);	
	DeleteObject(hBrownBrush);	
	DeleteObject(hDkGreenBrush); 
	DeleteObject(hCyanBrush);	
	DeleteObject(hLtGrayBrush);	
	DeleteObject(hLtPinkBrush);	
}

void StartDraw(HDC hDC)
{
	hdc = hDC;
    hOldPen = (HPEN)SelectObject(hdc, hBlackPen);
    SelectObject(hdc, hOldPen);
    hOldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(BLACK_BRUSH));
    SelectObject(hdc, hOldBrush);
}

void StopDraw()
{
    SelectObject(hdc, hOldPen);
    SelectObject(hdc, hOldBrush);
}

void DrawDot(int x, int y, COLORREF color)
{
	SetPixel( hdc, x, y, color );
}

void DrawDot(int x, int y, int color)
{
	SetPixel(hdc, x, y, colors[color]);
}

void Line(int x1, int y1, int x2, int y2)
{
	MoveToEx( hdc, x1, y1, NULL );
	LineTo( hdc, x2, y2 );
}

void Rect(int x1, int y1, int x2, int y2)
{
	Rectangle( hdc, x1, y1, x2, y2 );
}

void R_Rect(int x1, int y1, int x2, int y2, int w, int h)
{
	RoundRect( hdc, x1, y1, x2, y2, w, h );
}

void Circle(int x1, int y1, int x2, int y2)
{
	Ellipse( hdc, x1, y1, x2, y2 );
}

void Circle(int x, int y, int r)
{
	Ellipse( hdc, x-r, y-r, x+r, y+r);
}

void Poly(POINT pPt[], int n)
{
	Polygon( hdc, pPt, n );
}

void TextAtPos(int x, int y, char* string)
{
	TextOut(hdc, x, y, string, strlen(string));
}

void TransparentText()
{
	SetBkMode(hdc, TRANSPARENT);
}

void OpaqueText()
{
	SetBkMode(hdc, OPAQUE);
}

void TextColor(int color)
{
	SetTextColor(hdc, colors[color]);
}

void TextColor(int r, int g, int b)
{
	SetTextColor(hdc, RGB(r,g,b));
}

void BlackPen(){	if(hdc){	SelectObject(hdc, hBlackPen);	}	}
void WhitePen(){	if(hdc){SelectObject(hdc, hWhitePen);	}	}
void RedPen()  {	if(hdc){SelectObject(hdc, hRedPen);	}	}
void GreenPen(){	if(hdc){SelectObject(hdc, hGreenPen);	}	}
void BluePen() {	if(hdc){SelectObject(hdc, hBluePen);	}	}
void GrayPen() {	if(hdc){SelectObject(hdc, hGrayPen);	}	}
void PinkPen() {	if(hdc){SelectObject(hdc, hPinkPen);	}	}
void YellowPen() {	if(hdc){SelectObject(hdc, hYellowPen);	}	}
void OrangePen() {	if(hdc){SelectObject(hdc, hOrangePen);	}	}
void PurplePen() {	if(hdc){SelectObject(hdc, hPurplePen);	}	}
void BrownPen() {	if(hdc){SelectObject(hdc, hBrownPen);	}	}

void DarkGreenPen() {	if(hdc){SelectObject(hdc, hDkGreenPen);	}	}
void LightGrayPen() {	if(hdc){SelectObject(hdc, hLtGrayPen);	}	}
void LightPinkPen() {	if(hdc){SelectObject(hdc, hLtPinkPen);	}	}

void BlackBrush()	{if(hdc)SelectObject(hdc, GetStockObject(BLACK_BRUSH));}
void WhiteBrush()	{if(hdc)SelectObject(hdc, GetStockObject(WHITE_BRUSH));} 
void HollowBrush(){if(hdc)SelectObject(hdc, GetStockObject(HOLLOW_BRUSH));}
void GreenBrush() {if(hdc)SelectObject(hdc, hGreenBrush);}
void RedBrush() {	if(hdc)SelectObject(hdc, hRedBrush);}
void BlueBrush() {	if(hdc)SelectObject(hdc, hBlueBrush);}
void GrayBrush() {	if(hdc)SelectObject(hdc, hGrayBrush);}
void BrownBrush() {if(hdc)SelectObject(hdc, hBrownBrush);}
void YellowBrush() {if(hdc)SelectObject(hdc, hYellowBrush);}
void DarkGreenBrush(){if(hdc)SelectObject(hdc, hDkGreenBrush);}
void OrangeBrush() {if(hdc)SelectObject(hdc, hOrangeBrush);}