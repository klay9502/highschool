
// 9_01Doc.cpp : implementation of the CMy9_01Doc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "9_01.h"
#endif

#include "9_01Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy9_01Doc

IMPLEMENT_DYNCREATE(CMy9_01Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy9_01Doc, CDocument)
END_MESSAGE_MAP()


// CMy9_01Doc construction/destruction

CMy9_01Doc::CMy9_01Doc()
: m_pt(0)
{
	// TODO: add one-time construction code here
	m_pt = CPoint(100, 100);
	m_sz = CSize(100, 100);
	m_cr = RGB(255, 0, 0);
}

CMy9_01Doc::~CMy9_01Doc()
{
}

BOOL CMy9_01Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMy9_01Doc serialization

void CMy9_01Doc::Serialize(CArchive& ar)
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
void CMy9_01Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMy9_01Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMy9_01Doc::SetSearchContent(const CString& value)
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

// CMy9_01Doc diagnostics

#ifdef _DEBUG
void CMy9_01Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy9_01Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy9_01Doc commands


void CMy9_01Doc::SetPoint(CPoint _pt)
{
	m_pt = _pt;
	UpdateAllViews(NULL);
}


void CMy9_01Doc::SetSize(CSize _size)
{
	m_sz = _size;
	UpdateAllViews(NULL);
}


void CMy9_01Doc::SetColor(COLORREF _color)
{
	m_cr = _color;
	UpdateAllViews(NULL);
}


CPoint CMy9_01Doc::GetPoint()
{
	return m_pt;
}


CSize CMy9_01Doc::GetSize()
{
	return m_sz;
}


COLORREF CMy9_01Doc::GetColor()
{
	return m_cr;
}
