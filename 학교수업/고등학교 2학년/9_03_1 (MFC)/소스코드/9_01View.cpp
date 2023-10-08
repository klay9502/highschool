
// 9_01View.cpp : implementation of the CMy9_01View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "9_01.h"
#endif

#include "9_01Doc.h"
#include "9_01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy9_01View

IMPLEMENT_DYNCREATE(CMy9_01View, CView)

BEGIN_MESSAGE_MAP(CMy9_01View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_COLORS_BLACK, &CMy9_01View::OnColorsBlack)
	ON_COMMAND(ID_COLORS_BLUE, &CMy9_01View::OnColorsBlue)
	ON_COMMAND(ID_COLORS_GREEN, &CMy9_01View::OnColorsGreen)
	ON_COMMAND(ID_COLORS_CYAN, &CMy9_01View::OnColorsCyan)
	ON_COMMAND(ID_COLORS_RED, &CMy9_01View::OnColorsRed)
	ON_COMMAND(ID_COLORS_MAGENTA, &CMy9_01View::OnColorsMagenta)
	ON_COMMAND(ID_COLORS_YELLOW, &CMy9_01View::OnColorsYellow)
	ON_COMMAND(ID_COLORS_USER, &CMy9_01View::OnColorsUser)
	ON_UPDATE_COMMAND_UI(ID_COLORS_BLACK, &CMy9_01View::OnUpdateColorsBlack)
	ON_UPDATE_COMMAND_UI(ID_COLORS_BLUE, &CMy9_01View::OnUpdateColorsBlue)
	ON_UPDATE_COMMAND_UI(ID_COLORS_GREEN, &CMy9_01View::OnUpdateColorsGreen)
	ON_UPDATE_COMMAND_UI(ID_COLORS_CYAN, &CMy9_01View::OnUpdateColorsCyan)
	ON_UPDATE_COMMAND_UI(ID_COLORS_RED, &CMy9_01View::OnUpdateColorsRed)
	ON_UPDATE_COMMAND_UI(ID_COLORS_MAGENTA, &CMy9_01View::OnUpdateColorsMagenta)
	ON_UPDATE_COMMAND_UI(ID_COLORS_YELLOW, &CMy9_01View::OnUpdateColorsYellow)
	ON_UPDATE_COMMAND_UI(ID_COLORS_USER, &CMy9_01View::OnUpdateColorsUser)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_RECT_DECREASE, &CMy9_01View::OnRectDecrease)
	ON_COMMAND(ID_RECT_INCREASE, &CMy9_01View::OnRectIncrease)
END_MESSAGE_MAP()

// CMy9_01View construction/destruction

CMy9_01View::CMy9_01View()
: m_nCheck(4)
{
	// TODO: add construction code here

}

CMy9_01View::~CMy9_01View()
{
}

BOOL CMy9_01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy9_01View drawing

void CMy9_01View::OnDraw(CDC* pDC)
{
	CMy9_01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CBrush brush, *pOldB;
	CRect rect(pDoc->GetPoint(), pDoc->GetSize());

	brush.CreateSolidBrush(pDoc->GetColor());
	pOldB = pDC->SelectObject(&brush);

	pDC->Rectangle(rect);

	pOldB = pDC->SelectObject(&brush);

}


// CMy9_01View printing

BOOL CMy9_01View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy9_01View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy9_01View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy9_01View diagnostics

#ifdef _DEBUG
void CMy9_01View::AssertValid() const
{
	CView::AssertValid();
}

void CMy9_01View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy9_01Doc* CMy9_01View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy9_01Doc)));
	return (CMy9_01Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy9_01View message handlers


void CMy9_01View::OnColorsBlack()
{
	// TODO: Add your command handler code here
	CMy9_01Doc* pDoc = GetDocument();
	pDoc->SetColor(RGB(0, 0, 0));
	m_nCheck = 0;
}


void CMy9_01View::OnColorsBlue()
{
	// TODO: Add your command handler code here
	CMy9_01Doc* pDoc = GetDocument();
	pDoc->SetColor(RGB(0, 0, 255));
	m_nCheck = 1;
}


void CMy9_01View::OnColorsGreen()
{
	// TODO: Add your command handler code here
	CMy9_01Doc* pDoc = GetDocument();
	pDoc->SetColor(RGB(0, 255, 0));
	m_nCheck = 2;
}


void CMy9_01View::OnColorsCyan()
{
	// TODO: Add your command handler code here
	CMy9_01Doc* pDoc = GetDocument();
	pDoc->SetColor(RGB(0, 255, 255));
	m_nCheck = 3;
}


void CMy9_01View::OnColorsRed()
{
	// TODO: Add your command handler code here
	CMy9_01Doc* pDoc = GetDocument();
	pDoc->SetColor(RGB(255, 0, 0));
	m_nCheck = 4;
}


void CMy9_01View::OnColorsMagenta()
{
	// TODO: Add your command handler code here
	CMy9_01Doc* pDoc = GetDocument();
	pDoc->SetColor(RGB(255, 0, 255));
	m_nCheck = 5;
}


void CMy9_01View::OnColorsYellow()
{
	// TODO: Add your command handler code here
	CMy9_01Doc* pDoc = GetDocument();
	pDoc->SetColor(RGB(255, 255, 0));
	m_nCheck = 6;
}


void CMy9_01View::OnColorsUser()
{
	// TODO: Add your command handler code here
	CMy9_01Doc* pDoc = GetDocument();
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		pDoc->SetColor(dlg.GetColor());
		m_nCheck = 7;
	}
}


void CMy9_01View::OnUpdateColorsBlack(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nCheck == 0);
}


void CMy9_01View::OnUpdateColorsBlue(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nCheck == 1);
}


void CMy9_01View::OnUpdateColorsGreen(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nCheck == 2);
}


void CMy9_01View::OnUpdateColorsCyan(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nCheck == 3);
}


void CMy9_01View::OnUpdateColorsRed(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nCheck == 4);
}


void CMy9_01View::OnUpdateColorsMagenta(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nCheck == 5);
}


void CMy9_01View::OnUpdateColorsYellow(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nCheck == 6);
}


void CMy9_01View::OnUpdateColorsUser(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nCheck == 7);
}


void CMy9_01View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CMy9_01Doc* pDoc = GetDocument();
	CPoint pt = pDoc->GetPoint();
	CRect rt;
	GetClientRect(&rt);

	switch (nChar)
	{
	case VK_UP:
		pt.y -= 20;
		if (pt.y < -80)
		{
			pt.y = rt.bottom - 20;
		}
		break;
	case VK_DOWN:
		pt.y += 20;
		if (pt.y >= rt.bottom)
		{
			pt.y = rt.top - 80;
		}
		break;
	case VK_LEFT:
		pt.x -= 20;
		if (pt.x < -80)
		{
			pt.x = rt.right - 20;
		}
		break;
	case VK_RIGHT:
		pt.x += 20;
		if (pt.x >= rt.right)
		{
			pt.x = rt.left - 80;
		}
		break;
	}

	pDoc->SetPoint(pt);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy9_01View::OnRectDecrease()
{
	// TODO: Add your command handler code here
	CMy9_01Doc* pDoc = GetDocument();
	CSize sz = pDoc->GetSize();

	sz.cx -= 20;
	sz.cy -= 20;

	if (!(sz.cx <= 0 || sz.cy <= 0))
	{
		pDoc->SetSize(sz);
	}
}


void CMy9_01View::OnRectIncrease()
{
	// TODO: Add your command handler code here
	CMy9_01Doc* pDoc = GetDocument();
	CSize sz = pDoc->GetSize();

	sz.cx += 20;
	sz.cy += 20;

	pDoc->SetSize(sz);
}
