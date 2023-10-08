// ViewUpper.cpp : implementation file
//

#include "stdafx.h"
#include "11_17.h"
#include "11_17Doc.h"
#include "ViewUpper.h"


// CViewUpper

IMPLEMENT_DYNCREATE(CViewUpper, CView)

CViewUpper::CViewUpper()
{

}

CViewUpper::~CViewUpper()
{
}

BEGIN_MESSAGE_MAP(CViewUpper, CView)
END_MESSAGE_MAP()

CMy11_17Doc* CViewUpper::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy11_17Doc)));
	return (CMy11_17Doc*)m_pDocument;
}

// CViewUpper drawing

void CViewUpper::OnDraw(CDC* pDC)
{
	CMy11_17Doc* pDoc = GetDocument();
	// TODO: add draw code here
	pDC->TextOutA(5, 5, "대문자로 출력 하는 Veiw");
	CString str;
	str = pDoc->m_str;
	str.MakeUpper();
	pDC->TextOutA(5, 25, str);
}


// CViewUpper diagnostics

#ifdef _DEBUG
void CViewUpper::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CViewUpper::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CViewUpper message handlers
