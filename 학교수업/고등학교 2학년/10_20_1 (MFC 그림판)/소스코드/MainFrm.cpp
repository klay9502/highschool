
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "10_20.h"

#include "MainFrm.h"
#include "10_20Doc.h"
#include "10_20View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_MAINTO_VIEW, &CMainFrame::OnMaintoView)
	ON_COMMAND(ID_MAINTO_DOC, &CMainFrame::OnMaintoDoc)
	ON_COMMAND(ID_MAINTO_APP, &CMainFrame::OnMaintoApp)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
: m_strMain(_T(""))
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers



void CMainFrame::OnMaintoView()
{
	// TODO: Add your command handler code here
	CMy10_20View* pView = (CMy10_20View*)GetActiveView();
	pView->m_strView = "Main To View";
	pView->Invalidate();
}


void CMainFrame::OnMaintoDoc()
{
	// TODO: Add your command handler code here
	CMy10_20Doc* pDoc = (CMy10_20Doc*)GetActiveDocument();
	CMy10_20View* pView = (CMy10_20View*)GetActiveView();
	pDoc->m_strDoc = "Main To Doc";
	pView->m_strView = pDoc->m_strDoc;
	pView->Invalidate();
}


void CMainFrame::OnMaintoApp()
{
	// TODO: Add your command handler code here
	CMy10_20App* pApp = (CMy10_20App*)AfxGetApp();
	CMy10_20View* pView = (CMy10_20View*)GetActiveView();
	pApp->m_strApp = "Main To App";
	pView->m_strView = pApp->m_strApp;
	pView->Invalidate();
}
