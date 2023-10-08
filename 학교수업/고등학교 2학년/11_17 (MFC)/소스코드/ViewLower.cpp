// ViewLower.cpp : implementation file
//

#include "stdafx.h"
#include "11_17.h"
#include "11_17Doc.h"
#include "ViewLower.h"


// CViewLower

IMPLEMENT_DYNCREATE(CViewLower, CView)

CViewLower::CViewLower()
{

}

CViewLower::~CViewLower()
{
}

BEGIN_MESSAGE_MAP(CViewLower, CView)
END_MESSAGE_MAP()

CMy11_17Doc* CViewLower::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy11_17Doc)));
	return (CMy11_17Doc*)m_pDocument;
}

// CViewLower drawing

void CViewLower::OnDraw(CDC* pDC)
{
	CMy11_17Doc* pDoc = GetDocument();
	// TODO: add draw code here
	pDC->TextOutA(5, 5, "소문자로 출력 하는 Veiw");
	CString str;
	str = pDoc->m_str;
	str.MakeLower();
	pDC->TextOutA(5, 25, str);
}


// CViewLower diagnostics

#ifdef _DEBUG
void CViewLower::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CViewLower::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CViewLower message handlers
