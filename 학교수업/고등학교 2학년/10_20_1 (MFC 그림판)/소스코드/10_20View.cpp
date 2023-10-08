
// 10_20View.cpp : implementation of the CMy10_20View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "10_20.h"
#endif

#include "10_20Doc.h"
#include "10_20View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy10_20View

IMPLEMENT_DYNCREATE(CMy10_20View, CView)

BEGIN_MESSAGE_MAP(CMy10_20View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_VIEWTO_DOC, &CMy10_20View::OnViewtoDoc)
	ON_COMMAND(ID_VIEWTO_MAIN, &CMy10_20View::OnViewtoMain)
	ON_COMMAND(ID_VIEWTO_APP, &CMy10_20View::OnViewtoApp)
END_MESSAGE_MAP()

// CMy10_20View construction/destruction

CMy10_20View::CMy10_20View()
: m_strView(_T(""))
{
	// TODO: add construction code here

}

CMy10_20View::~CMy10_20View()
{
}

BOOL CMy10_20View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy10_20View drawing

void CMy10_20View::OnDraw(CDC* pDC)
{
	CMy10_20Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	pDC->TextOutA(0, 0, "4대 클래스간에 데이터 전송 프로그램");
	pDC->TextOutA(100, 50, m_strView);
}


// CMy10_20View printing

BOOL CMy10_20View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy10_20View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy10_20View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy10_20View diagnostics

#ifdef _DEBUG
void CMy10_20View::AssertValid() const
{
	CView::AssertValid();
}

void CMy10_20View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy10_20Doc* CMy10_20View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy10_20Doc)));
	return (CMy10_20Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy10_20View message handlers


void CMy10_20View::OnViewtoDoc()
{
	// TODO: Add your command handler code here
	CMy10_20Doc* pDoc = GetDocument();
	pDoc->m_strDoc = "View To Doc";
	m_strView = pDoc->m_strDoc;
	Invalidate();
}


void CMy10_20View::OnViewtoMain()
{
	// TODO: Add your command handler code here
	CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd();
	pMain->m_strMain = "View To Main";
	m_strView = pMain->m_strMain;
	Invalidate();
}


void CMy10_20View::OnViewtoApp()
{
	// TODO: Add your command handler code here
	CMy10_20App* pApp = (CMy10_20App*)AfxGetApp();
	pApp->m_strApp = "View To App";
	m_strView = pApp->m_strApp;
	Invalidate();
}
