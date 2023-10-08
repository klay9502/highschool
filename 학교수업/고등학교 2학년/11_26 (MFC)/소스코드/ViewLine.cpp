// ViewLine.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ViewLine.h"
#include "MFCApplication1Doc.h"


// CViewLine

IMPLEMENT_DYNCREATE(CViewLine, CView)

CViewLine::CViewLine()
{

}

CViewLine::~CViewLine()
{
}

BEGIN_MESSAGE_MAP(CViewLine, CView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CViewLine drawing

void CViewLine::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	pDC->TextOutA(0, 0, "¼± ±×¸®±â");
}


// CViewLine diagnostics

#ifdef _DEBUG
void CViewLine::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CViewLine::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CViewLine message handlers


int CViewLine::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	SetTimer(1, 100, NULL);
	srand((unsigned)time(NULL));

	return 0;
}


void CViewLine::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	KillTimer(1);
}


void CViewLine::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CMFCApplication1Doc* pDoc = (CMFCApplication1Doc*)GetDocument();
	CClientDC dc(this);

	CRect r;
	GetClientRect(&r);
	// ÁÂÇ¥
	pDoc->m_pt.x = rand() % r.right;
	pDoc->m_pt2.x = rand() % r.right;
	pDoc->m_pt.y = rand() % r.bottom;
	pDoc->m_pt2.y = rand() % r.bottom;

	// »ö»ó
	pDoc->r = rand() % 256;
	pDoc->g = rand() % 256;
	pDoc->b = rand() % 256;

	// ±½±â
	pDoc->thick = rand() % 10 + 1;

	CPen *pOldP;
	CPen pen(PS_SOLID, pDoc->thick, RGB(pDoc->r, pDoc->g, pDoc->b));
	pOldP = dc.SelectObject(&pen);
	dc.MoveTo(pDoc->m_pt.x, pDoc->m_pt.y);
	dc.LineTo(pDoc->m_pt2.x, pDoc->m_pt2.y);
	dc.SelectObject(pOldP);

	CView::OnTimer(nIDEvent);
}
