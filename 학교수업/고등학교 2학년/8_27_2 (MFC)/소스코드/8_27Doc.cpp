
// 8_27Doc.cpp : CMy8_27Doc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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


// CMy8_27Doc ����/�Ҹ�

CMy8_27Doc::CMy8_27Doc()
: m_pt(0)
, m_str(_T(""))
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
	m_str = "��õ�� ����";
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

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CMy8_27Doc serialization

void CMy8_27Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CMy8_27Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
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

// �˻� ó���⸦ �����մϴ�.
void CMy8_27Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
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

// CMy8_27Doc ����

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


// CMy8_27Doc ���


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
