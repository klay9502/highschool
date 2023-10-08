
// 10_20Doc.cpp : implementation of the CMy10_20Doc class
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

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy10_20Doc

IMPLEMENT_DYNCREATE(CMy10_20Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy10_20Doc, CDocument)
	ON_COMMAND(ID_DOCTO_VIEW, &CMy10_20Doc::OnDoctoView)
	ON_COMMAND(ID_DOCTO_MAIN, &CMy10_20Doc::OnDoctoMain)
	ON_COMMAND(ID_DOCTO_APP, &CMy10_20Doc::OnDoctoApp)
END_MESSAGE_MAP()


// CMy10_20Doc construction/destruction

CMy10_20Doc::CMy10_20Doc()
: m_strDoc(_T(""))
{
	// TODO: add one-time construction code here

}

CMy10_20Doc::~CMy10_20Doc()
{
}

BOOL CMy10_20Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMy10_20Doc serialization

void CMy10_20Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMy10_20Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMy10_20Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMy10_20Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy10_20Doc diagnostics

#ifdef _DEBUG
void CMy10_20Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy10_20Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy10_20Doc commands


void CMy10_20Doc::OnDoctoView()
{
	// TODO: Add your command handler code here
	CMy10_20View* pView = (CMy10_20View*)m_viewList.GetHead();
	pView->m_strView = "Doc To View";
	pView->Invalidate();
}


void CMy10_20Doc::OnDoctoMain()
{
	// TODO: Add your command handler code here
	CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd();
	CMy10_20View* pView = (CMy10_20View*)m_viewList.GetHead();
	pMain->m_strMain = "Doc To Main";
	pView->m_strView = pMain->m_strMain;
	pView->Invalidate();
}


void CMy10_20Doc::OnDoctoApp()
{
	// TODO: Add your command handler code here
	CMy10_20App* pApp = (CMy10_20App*)AfxGetApp();
	CMy10_20View* pView = (CMy10_20View*)m_viewList.GetHead();
	pApp->m_strApp = "Doc To App";
	pView->m_strView = pApp->m_strApp;
	pView->Invalidate();
}
