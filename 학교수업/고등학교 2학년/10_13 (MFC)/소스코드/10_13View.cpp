
// 10_13View.cpp : implementation of the CMy10_13View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "10_13.h"
#endif

#include "10_13Doc.h"
#include "10_13View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy10_13View

IMPLEMENT_DYNCREATE(CMy10_13View, CView)

BEGIN_MESSAGE_MAP(CMy10_13View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_COLORS_BLACK, &CMy10_13View::OnColorsBlack)
	ON_COMMAND(ID_COLORS_BLUE, &CMy10_13View::OnColorsBlue)
	ON_COMMAND(ID_COLORS_GREEN, &CMy10_13View::OnColorsGreen)
	ON_COMMAND(ID_COLORS_CYAN, &CMy10_13View::OnColorsCyan)
	ON_COMMAND(ID_COLORS_RED, &CMy10_13View::OnColorsRed)
	ON_COMMAND(ID_COLORS_MAGENTA, &CMy10_13View::OnColorsMagenta)
	ON_COMMAND(ID_COLORS_YELLOW, &CMy10_13View::OnColorsYellow)
	ON_COMMAND(ID_COLORS_USER, &CMy10_13View::OnColorsUser)
	ON_COMMAND(ID_WIDTH_1, &CMy10_13View::OnWidth1)
	ON_COMMAND(ID_WIDTH_2, &CMy10_13View::OnWidth2)
	ON_COMMAND(ID_WIDTH_3, &CMy10_13View::OnWidth3)
	ON_COMMAND(ID_WIDTH_5, &CMy10_13View::OnWidth5)
	ON_COMMAND(ID_WIDTH_10, &CMy10_13View::OnWidth10)
	ON_COMMAND(ID_TOOL_PEN, &CMy10_13View::OnToolPen)
	ON_COMMAND(ID_TOOL_LINE, &CMy10_13View::OnToolLine)
	ON_COMMAND(ID_TOOL_ELLIPSE, &CMy10_13View::OnToolEllipse)
	ON_COMMAND(ID_TOOL_RECT, &CMy10_13View::OnToolRect)
	ON_COMMAND(ID_TOOL_ROUNDRECT, &CMy10_13View::OnToolRoundrect)
	ON_COMMAND(ID_TOOL_ERASE, &CMy10_13View::OnToolErase)
	ON_COMMAND(ID_TOOL_FILL, &CMy10_13View::OnToolFill)
	ON_COMMAND(ID_BRUSH_BLACK, &CMy10_13View::OnBrushBlack)
	ON_COMMAND(ID_BRUSH_BLUE, &CMy10_13View::OnBrushBlue)
	ON_COMMAND(ID_BRUSH_GREEN, &CMy10_13View::OnBrushGreen)
	ON_COMMAND(ID_BRUSH_CYAN, &CMy10_13View::OnBrushCyan)
	ON_COMMAND(ID_BRUSH_RED, &CMy10_13View::OnBrushRed)
	ON_COMMAND(ID_BRUSH_MAGENTA, &CMy10_13View::OnBrushMagenta)
	ON_COMMAND(ID_BRUSH_YELLOW, &CMy10_13View::OnBrushYellow)
	ON_COMMAND(ID_BRUSH_WHITE, &CMy10_13View::OnBrushWhite)
	ON_COMMAND(ID_BRUSH_USER, &CMy10_13View::OnBrushUser)
	ON_UPDATE_COMMAND_UI(ID_COLORS_BLACK, &CMy10_13View::OnUpdateColorsBlack)
	ON_UPDATE_COMMAND_UI(ID_COLORS_BLUE, &CMy10_13View::OnUpdateColorsBlue)
	ON_UPDATE_COMMAND_UI(ID_COLORS_GREEN, &CMy10_13View::OnUpdateColorsGreen)
	ON_UPDATE_COMMAND_UI(ID_COLORS_CYAN, &CMy10_13View::OnUpdateColorsCyan)
	ON_UPDATE_COMMAND_UI(ID_COLORS_RED, &CMy10_13View::OnUpdateColorsRed)
	ON_UPDATE_COMMAND_UI(ID_COLORS_MAGENTA, &CMy10_13View::OnUpdateColorsMagenta)
	ON_UPDATE_COMMAND_UI(ID_COLORS_YELLOW, &CMy10_13View::OnUpdateColorsYellow)
	ON_UPDATE_COMMAND_UI(ID_COLORS_USER, &CMy10_13View::OnUpdateColorsUser)
	ON_UPDATE_COMMAND_UI(ID_WIDTH_1, &CMy10_13View::OnUpdateWidth1)
	ON_UPDATE_COMMAND_UI(ID_WIDTH_2, &CMy10_13View::OnUpdateWidth2)
	ON_UPDATE_COMMAND_UI(ID_WIDTH_3, &CMy10_13View::OnUpdateWidth3)
	ON_UPDATE_COMMAND_UI(ID_WIDTH_5, &CMy10_13View::OnUpdateWidth5)
	ON_UPDATE_COMMAND_UI(ID_WIDTH_10, &CMy10_13View::OnUpdateWidth10)
	ON_UPDATE_COMMAND_UI(ID_TOOL_PEN, &CMy10_13View::OnUpdateToolPen)
	ON_UPDATE_COMMAND_UI(ID_TOOL_LINE, &CMy10_13View::OnUpdateToolLine)
	ON_UPDATE_COMMAND_UI(ID_TOOL_ELLIPSE, &CMy10_13View::OnUpdateToolEllipse)
	ON_UPDATE_COMMAND_UI(ID_TOOL_RECT, &CMy10_13View::OnUpdateToolRect)
	ON_UPDATE_COMMAND_UI(ID_TOOL_ROUNDRECT, &CMy10_13View::OnUpdateToolRoundrect)
	ON_UPDATE_COMMAND_UI(ID_TOOL_ERASE, &CMy10_13View::OnUpdateToolErase)
	ON_UPDATE_COMMAND_UI(ID_TOOL_FILL, &CMy10_13View::OnUpdateToolFill)
	ON_UPDATE_COMMAND_UI(ID_BRUSH_BLACK, &CMy10_13View::OnUpdateBrushBlack)
	ON_UPDATE_COMMAND_UI(ID_BRUSH_BLUE, &CMy10_13View::OnUpdateBrushBlue)
	ON_UPDATE_COMMAND_UI(ID_BRUSH_GREEN, &CMy10_13View::OnUpdateBrushGreen)
	ON_UPDATE_COMMAND_UI(ID_BRUSH_CYAN, &CMy10_13View::OnUpdateBrushCyan)
	ON_UPDATE_COMMAND_UI(ID_BRUSH_RED, &CMy10_13View::OnUpdateBrushRed)
	ON_UPDATE_COMMAND_UI(ID_BRUSH_MAGENTA, &CMy10_13View::OnUpdateBrushMagenta)
	ON_UPDATE_COMMAND_UI(ID_BRUSH_YELLOW, &CMy10_13View::OnUpdateBrushYellow)
	ON_UPDATE_COMMAND_UI(ID_BRUSH_WHITE, &CMy10_13View::OnUpdateBrushWhite)
	ON_UPDATE_COMMAND_UI(ID_BRUSH_USER, &CMy10_13View::OnUpdateBrushUser)
	ON_WM_SETCURSOR()
	ON_WM_CREATE()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()

// CMy10_13View construction/destruction

CMy10_13View::CMy10_13View()
: m_nTool(0)
, m_nWidth(0)
, m_bIsDraw(FALSE)
, m_ptStart(0)
, m_ptOld(0)
{
	// TODO: add construction code here
	m_crBr = MAGENTA;
	m_nTool = DPEN;
	m_bIsDraw = FALSE;
	m_crPen = BLUE;
	m_nWidth = 2;
	m_nPenCheak = m_crPen;
	m_nWidthCheak = m_nWidth;
	m_nToolCheak = m_nTool;
	m_nBrushCheak = m_crBr;
}

CMy10_13View::~CMy10_13View()
{
}

BOOL CMy10_13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy10_13View drawing

void CMy10_13View::OnDraw(CDC* /*pDC*/)
{
	CMy10_13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMy10_13View printing

BOOL CMy10_13View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy10_13View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy10_13View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy10_13View diagnostics

#ifdef _DEBUG
void CMy10_13View::AssertValid() const
{
	CView::AssertValid();
}

void CMy10_13View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy10_13Doc* CMy10_13View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy10_13Doc)));
	return (CMy10_13Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy10_13View message handlers


void CMy10_13View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	SetCapture();

	CClientDC dc(this);
	m_bIsDraw = TRUE;
	m_ptStart = m_ptOld = point;

	CBrush brush, *pOldB;
	brush.CreateSolidBrush(m_crBr);
	pOldB = dc.SelectObject(&brush);

	if (m_nTool == DFILL)
	{
		COLORREF color = dc.GetPixel(point);
		dc.ExtFloodFill(point.x, point.y, color, FLOODFILLSURFACE);
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMy10_13View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	ReleaseCapture();

	m_bIsDraw = FALSE;

	CClientDC dc(this);
	CPen Pen, *pOldPen;
	Pen.CreatePen(PS_SOLID, m_nWidth, m_crPen);
	pOldPen = dc.SelectObject(&Pen);

	CBrush Brush, *pOldBrush;
	Brush.CreateSolidBrush(m_crBr);
	pOldBrush = dc.SelectObject(&Brush);

	switch (m_nTool)
	{
	case DLINE:
		dc.MoveTo(m_ptStart);
		dc.LineTo(point);
		break;
	case DELLIPSE:
		dc.Ellipse(m_ptStart.x, m_ptStart.y, point.x, point.y);
		break;
	case DROUNDRECT:
		dc.RoundRect(m_ptStart.x, m_ptStart.y, point.x, point.y, 20, 20);
		break;
	case DRECT:
		dc.Rectangle(m_ptStart.x, m_ptStart.y, point.x, point.y);
		break;
	case DERASE:
		dc.SelectStockObject(WHITE_PEN);
		dc.SelectStockObject(WHITE_BRUSH);
		dc.Ellipse(point.x - 50, point.y - 50, point.x + 50, point.y + 50);
		break;
	}

	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);

	CView::OnLButtonUp(nFlags, point);
}


void CMy10_13View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);

	if (!m_bIsDraw)
	{
		// 만약 왼쪽마우스 버튼을 누르지 않았다면 리턴한다.
		return;
	}

	CPen Pen, *pOldPen;
	Pen.CreatePen(PS_SOLID, m_nWidth, m_crPen);
	pOldPen = dc.SelectObject(&Pen);

	CBrush Brush, *pOldBrush;
	Brush.CreateSolidBrush(m_crBr);
	pOldBrush = dc.SelectObject(&Brush);

	if (m_nTool == DPEN)
	{
		dc.MoveTo(m_ptOld);
		dc.LineTo(point);
	}

	if (m_nTool == DERASE)
	{
		dc.SelectStockObject(WHITE_PEN);
		dc.SelectStockObject(WHITE_BRUSH);
		dc.Ellipse(m_ptOld.x - 50, m_ptOld.y - 50, m_ptOld.x + 50, m_ptOld.y + 50);
		dc.SelectStockObject(BLACK_PEN);
		dc.Ellipse(point.x - 50, point.y - 50, point.x + 50, point.y + 50);
	}

	dc.SetROP2(R2_NOTXORPEN);

	switch (m_nTool)
	{
	case DLINE:
		dc.MoveTo(m_ptStart);
		dc.LineTo(m_ptOld);
		dc.MoveTo(m_ptStart);
		dc.LineTo(point);
		break;
	case DELLIPSE:
		dc.Ellipse(m_ptStart.x, m_ptStart.y, m_ptOld.x, m_ptOld.y);
		dc.Ellipse(m_ptStart.x, m_ptStart.y, point.x, point.y);
		break;
	case DROUNDRECT:
		dc.RoundRect(m_ptStart.x, m_ptStart.y, m_ptOld.x, m_ptOld.y, 20, 20);
		dc.RoundRect(m_ptStart.x, m_ptStart.y, point.x, point.y, 20, 20);
		break;
	case DRECT:
		dc.Rectangle(m_ptStart.x, m_ptStart.y, m_ptOld.x, m_ptOld.y);
		dc.Rectangle(m_ptStart.x, m_ptStart.y, point.x, point.y);
		break;
	}

	m_ptOld = point;
	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);

	CView::OnMouseMove(nFlags, point);
}


void CMy10_13View::OnColorsBlack()
{
	// TODO: Add your command handler code here
	m_crPen = m_nPenCheak = BLACK;
}


void CMy10_13View::OnColorsBlue()
{
	// TODO: Add your command handler code here
	m_crPen = m_nPenCheak = BLUE;
}


void CMy10_13View::OnColorsGreen()
{
	// TODO: Add your command handler code here
	m_crPen = m_nPenCheak = GREEN;
}


void CMy10_13View::OnColorsCyan()
{
	// TODO: Add your command handler code here
	m_crPen = m_nPenCheak = CYAN;
}


void CMy10_13View::OnColorsRed()
{
	// TODO: Add your command handler code here
	m_crPen = m_nPenCheak = RED;
}


void CMy10_13View::OnColorsMagenta()
{
	// TODO: Add your command handler code here
	m_crPen = m_nPenCheak = MAGENTA;
}


void CMy10_13View::OnColorsYellow()
{
	// TODO: Add your command handler code here
	m_crPen = m_nPenCheak = YELLOW;
}


void CMy10_13View::OnColorsUser()
{
	// TODO: Add your command handler code here
	CColorDialog dlg;

	if (dlg.DoModal() == IDOK)
	{
		m_crPen = dlg.GetColor();
	}

	m_nPenCheak = m_nPenCheak = 7;
}


void CMy10_13View::OnWidth1()
{
	// TODO: Add your command handler code here
	m_nWidth = m_nWidthCheak = 1;
}


void CMy10_13View::OnWidth2()
{
	// TODO: Add your command handler code here
	m_nWidth = m_nWidthCheak = 2;
}


void CMy10_13View::OnWidth3()
{
	// TODO: Add your command handler code here
	m_nWidth = m_nWidthCheak = 3;
}


void CMy10_13View::OnWidth5()
{
	// TODO: Add your command handler code here
	m_nWidth = m_nWidthCheak = 5;
}


void CMy10_13View::OnWidth10()
{
	// TODO: Add your command handler code here
	m_nWidth = m_nWidthCheak = 10;
}


void CMy10_13View::OnToolPen()
{
	// TODO: Add your command handler code here
	m_nTool = m_nToolCheak = DPEN;
}


void CMy10_13View::OnToolLine()
{
	// TODO: Add your command handler code here
	m_nTool = m_nToolCheak = DLINE;
}


void CMy10_13View::OnToolEllipse()
{
	// TODO: Add your command handler code here
	m_nTool = m_nToolCheak = DELLIPSE;
}


void CMy10_13View::OnToolRect()
{
	// TODO: Add your command handler code here
	m_nTool = m_nToolCheak = DRECT;
}


void CMy10_13View::OnToolRoundrect()
{
	// TODO: Add your command handler code here
	m_nTool = m_nToolCheak = DROUNDRECT;
}


void CMy10_13View::OnToolErase()
{
	// TODO: Add your command handler code here
	m_nTool = m_nToolCheak = DERASE;
}


void CMy10_13View::OnToolFill()
{
	// TODO: Add your command handler code here
	m_nTool = m_nToolCheak = DFILL;
}


void CMy10_13View::OnBrushBlack()
{
	// TODO: Add your command handler code here
	m_crBr = m_nBrushCheak = BLACK;
}


void CMy10_13View::OnBrushBlue()
{
	// TODO: Add your command handler code here
	m_crBr = m_nBrushCheak = BLUE;
}


void CMy10_13View::OnBrushGreen()
{
	// TODO: Add your command handler code here
	m_crBr = m_nBrushCheak = GREEN;
}


void CMy10_13View::OnBrushCyan()
{
	// TODO: Add your command handler code here
	m_crBr = m_nBrushCheak = CYAN;
}


void CMy10_13View::OnBrushRed()
{
	// TODO: Add your command handler code here
	m_crBr = m_nBrushCheak = RED;
}


void CMy10_13View::OnBrushMagenta()
{
	// TODO: Add your command handler code here
	m_crBr = m_nBrushCheak = MAGENTA;
}


void CMy10_13View::OnBrushYellow()
{
	// TODO: Add your command handler code here
	m_crBr = m_nBrushCheak = YELLOW;
}


void CMy10_13View::OnBrushWhite()
{
	// TODO: Add your command handler code here
	m_crBr = m_nBrushCheak = WHITE;
}


void CMy10_13View::OnBrushUser()
{
	// TODO: Add your command handler code here
	CColorDialog dlg;

	if (dlg.DoModal() == IDOK)
	{
		m_crBr = dlg.GetColor();
	}

	m_nBrushCheak = 9;
}


void CMy10_13View::OnUpdateColorsBlack(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nPenCheak == BLACK);
}


void CMy10_13View::OnUpdateColorsBlue(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nPenCheak == BLUE);
}


void CMy10_13View::OnUpdateColorsGreen(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nPenCheak == GREEN);
}


void CMy10_13View::OnUpdateColorsCyan(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nPenCheak == CYAN);
}


void CMy10_13View::OnUpdateColorsRed(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nPenCheak == RED);
}


void CMy10_13View::OnUpdateColorsMagenta(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nPenCheak == MAGENTA);
}


void CMy10_13View::OnUpdateColorsYellow(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nPenCheak == YELLOW);
}


void CMy10_13View::OnUpdateColorsUser(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nPenCheak == 7);
}


void CMy10_13View::OnUpdateWidth1(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nWidthCheak == 1);
}


void CMy10_13View::OnUpdateWidth2(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nWidthCheak == 2);
}


void CMy10_13View::OnUpdateWidth3(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nWidthCheak == 3);
}


void CMy10_13View::OnUpdateWidth5(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nWidthCheak == 5);
}


void CMy10_13View::OnUpdateWidth10(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nWidthCheak == 10);
}


void CMy10_13View::OnUpdateToolPen(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nToolCheak == DPEN);
}


void CMy10_13View::OnUpdateToolLine(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nToolCheak == DLINE);
}


void CMy10_13View::OnUpdateToolEllipse(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nToolCheak == DELLIPSE);
}


void CMy10_13View::OnUpdateToolRect(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nToolCheak == DRECT);
}


void CMy10_13View::OnUpdateToolRoundrect(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nToolCheak == DROUNDRECT);
}


void CMy10_13View::OnUpdateToolErase(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nToolCheak == DERASE);
}


void CMy10_13View::OnUpdateToolFill(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nToolCheak == DFILL);
}


void CMy10_13View::OnUpdateBrushBlack(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nBrushCheak == BLACK);
}


void CMy10_13View::OnUpdateBrushBlue(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nBrushCheak == BLUE);
}


void CMy10_13View::OnUpdateBrushGreen(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nBrushCheak == GREEN);
}


void CMy10_13View::OnUpdateBrushCyan(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nBrushCheak == CYAN);
}


void CMy10_13View::OnUpdateBrushRed(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nBrushCheak == RED);
}


void CMy10_13View::OnUpdateBrushMagenta(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nBrushCheak == MAGENTA);
}


void CMy10_13View::OnUpdateBrushYellow(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nBrushCheak == YELLOW);
}


void CMy10_13View::OnUpdateBrushWhite(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nBrushCheak == WHITE);
}


void CMy10_13View::OnUpdateBrushUser(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nBrushCheak == 9);
}


int CMy10_13View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	hPen = AfxGetApp()->LoadCursorA(IDC_PEN);
	hLine = AfxGetApp()->LoadCursorA(IDC_LINE);
	hRect = AfxGetApp()->LoadCursorA(IDC_RECT);
	hRoundRect = AfxGetApp()->LoadCursorA(IDC_ROUNDRECT);
	hEllipse = AfxGetApp()->LoadCursorA(IDC_ELLIPSE);
	hFill = AfxGetApp()->LoadCursorA(IDC_FILL);

	return 0;
}


BOOL CMy10_13View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default

	switch (m_nTool)
	{
	case DPEN:
		SetCursor(hPen);
		break;
	case DLINE:
		SetCursor(hLine);
		break;
	case DELLIPSE:
		SetCursor(hEllipse);
		break;
	case DRECT:
		SetCursor(hRect);
		break;
	case DROUNDRECT:
		SetCursor(hRoundRect);
		break;
	case DFILL:
		SetCursor(hFill);
		break;
	}

	return true;

	return CView::OnSetCursor(pWnd, nHitTest, message);
}
