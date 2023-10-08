// ViewRect.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ViewRect.h"
#include "MFCApplication1Doc.h"


// CViewRect

IMPLEMENT_DYNCREATE(CViewRect, CView)

CViewRect::CViewRect()
{

}

CViewRect::~CViewRect()
{
}

BEGIN_MESSAGE_MAP(CViewRect, CView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CViewRect drawing

void CViewRect::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	pDC->TextOutA(0, 0, "사각형 그리기");
}


// CViewRect diagnostics

#ifdef _DEBUG
void CViewRect::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CViewRect::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CViewRect message handlers


int CViewRect::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	SetTimer(1, 100, NULL);
	srand((unsigned)time(NULL));

	return 0;
}


void CViewRect::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	KillTimer(1);
}


void CViewRect::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CMFCApplication1Doc* pDoc = (CMFCApplication1Doc*)GetDocument();
	CClientDC dc(this);

	CRect r;
	GetClientRect(&r);

	// 좌표
	pDoc->m_pt.x = rand() % r.right;
	pDoc->m_pt2.x = rand() % r.right;
	pDoc->m_pt.y = rand() % r.bottom;
	pDoc->m_pt2.y = rand() % r.bottom;

	// 색상
	pDoc->r = rand() % 256;
	pDoc->g = rand() % 256;
	pDoc->b = rand() % 256;

	CBrush *pOldB, brush(RGB(pDoc->r, pDoc->g, pDoc->b));
	pOldB = dc.SelectObject(&brush);
	dc.Rectangle(pDoc->m_pt.x, pDoc->m_pt.y, pDoc->m_pt2.x, pDoc->m_pt2.y);
	dc.SelectObject(pOldB);

	CView::OnTimer(nIDEvent);
}
