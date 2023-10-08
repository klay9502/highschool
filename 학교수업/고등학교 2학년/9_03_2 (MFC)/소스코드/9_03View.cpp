
// 9_03View.cpp : implementation of the CMy9_03View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "9_03.h"
#endif

#include "9_03Doc.h"
#include "9_03View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy9_03View

IMPLEMENT_DYNCREATE(CMy9_03View, CView)

BEGIN_MESSAGE_MAP(CMy9_03View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_TIME, &CMy9_03View::OnUpdateIndicatorTime)
	ON_COMMAND(ID_TIMER_ON, &CMy9_03View::OnTimerOn)
	ON_COMMAND(ID_TIMER_OFF, &CMy9_03View::OnTimerOff)
END_MESSAGE_MAP()

// CMy9_03View construction/destruction

CMy9_03View::CMy9_03View()
: m_strTime(_T(""))
{
	// TODO: add construction code here

}

CMy9_03View::~CMy9_03View()
{
}

BOOL CMy9_03View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy9_03View drawing

void CMy9_03View::OnDraw(CDC* pDC)
{
	CMy9_03Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(255, 255, 0));

	CFont font, *pOldF;
	font.CreateFontA(35, 0, 50, 0, 700, 0, 1, 0, 1, 0, 0, 0, 0, "±Ã¼­Ã¼");
	pOldF = pDC->SelectObject(&font);
	pDC->DrawText(m_strTime, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	pDC->SelectObject(pOldF);
}


// CMy9_03View printing

BOOL CMy9_03View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy9_03View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy9_03View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy9_03View diagnostics

#ifdef _DEBUG
void CMy9_03View::AssertValid() const
{
	CView::AssertValid();
}

void CMy9_03View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy9_03Doc* CMy9_03View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy9_03Doc)));
	return (CMy9_03Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy9_03View message handlers


int CMy9_03View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	SendMessage(WM_TIMER);
	SetTimer(1, 1000, NULL);
	return 0;
}


void CMy9_03View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	CTime t = CTime::GetCurrentTime();
	m_strTime = t.Format("%Y/%m/%d %H:%M:%S(%A)");
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMy9_03View::OnUpdateIndicatorTime(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetText(m_strTime);
	pCmdUI->Enable();
}


void CMy9_03View::OnTimerOn()
{
	// TODO: Add your command handler code here
	SendMessage(WM_TIMER);
	SetTimer(1, 1000, NULL);
}


void CMy9_03View::OnTimerOff()
{
	// TODO: Add your command handler code here
	KillTimer(1);
}
