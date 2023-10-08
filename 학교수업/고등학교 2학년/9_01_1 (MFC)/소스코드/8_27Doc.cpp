
// 8_27Doc.cpp : CMy8_27Doc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "8_27.h"
#endif

#include "8_27Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy8_27Doc

IMPLEMENT_DYNCREATE(CMy8_27Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy8_27Doc, CDocument)
END_MESSAGE_MAP()


// CMy8_27Doc 생성/소멸

CMy8_27Doc::CMy8_27Doc()
: m_pt(0)
, m_str(_T(""))
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
	m_str = "초천재 종민";
	m_pt = CPoint(0, 0);
	m_cr = RGB(0, 0, 255);
}

CMy8_27Doc::~CMy8_27Doc()
{
}

BOOL CMy8_27Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CMy8_27Doc serialization

void CMy8_27Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CMy8_27Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
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

// 검색 처리기를 지원합니다.
void CMy8_27Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMy8_27Doc::SetSearchContent(const CString& value)
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

// CMy8_27Doc 진단

#ifdef _DEBUG
void CMy8_27Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy8_27Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy8_27Doc 명령


void CMy8_27Doc::setString(CString _str)
{
	m_str = _str;
	UpdateAllViews(NULL);
}


void CMy8_27Doc::setPoint(CPoint _pt)
{
	m_pt = _pt;
	UpdateAllViews(NULL);
}


void CMy8_27Doc::setColor(COLORREF _cr)
{
	m_cr = _cr;
	UpdateAllViews(NULL);
}


CString CMy8_27Doc::getString()
{
	return m_str;
}


CPoint CMy8_27Doc::getPoint()
{
	return m_pt;
}


COLORREF CMy8_27Doc::getColor()
{
	return m_cr;
}
