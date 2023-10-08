// ViewCount.cpp : implementation file
//

#include "stdafx.h"
#include "11_17.h"
#include "11_17Doc.h"
#include "ViewCount.h"


// CViewCount

IMPLEMENT_DYNCREATE(CViewCount, CView)

CViewCount::CViewCount()
{

}

CViewCount::~CViewCount()
{
}

BEGIN_MESSAGE_MAP(CViewCount, CView)
END_MESSAGE_MAP()

CMy11_17Doc* CViewCount::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy11_17Doc)));
	return (CMy11_17Doc*)m_pDocument;
}

// CViewCount drawing

void CViewCount::OnDraw(CDC* pDC)
{
	CMy11_17Doc* pDoc = GetDocument();
	// TODO: add draw code here
	pDC->TextOutA(5, 5, "문자 카운트 하는 Veiw");
	CString str;
	int count;
	str = pDoc->m_str;
	count = str.GetLength();
	str.Format("count = %d", str.GetLength());
	pDC->TextOutA(5, 25, str);
}


// CViewCount diagnostics

#ifdef _DEBUG
void CViewCount::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CViewCount::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CViewCount message handlers
