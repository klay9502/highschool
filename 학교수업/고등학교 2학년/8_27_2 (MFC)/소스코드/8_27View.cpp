
// 8_27View.cpp : CMy8_27View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "8_27.h"
#endif

#include "8_27Doc.h"
#include "8_27View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy8_27View

IMPLEMENT_DYNCREATE(CMy8_27View, CView)

BEGIN_MESSAGE_MAP(CMy8_27View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_TEXT_BLACK, &CMy8_27View::OnTextBlack)
	ON_COMMAND(ID_TEXT_BLUE, &CMy8_27View::OnTextBlue)
	ON_COMMAND(ID_TEXT_GREEN, &CMy8_27View::OnTextGreen)
	ON_COMMAND(ID_TEXT_CYAN, &CMy8_27View::OnTextCyan)
	ON_COMMAND(ID_TEXT_RED, &CMy8_27View::OnTextRed)
	ON_COMMAND(ID_TEXT_MAGENTA, &CMy8_27View::OnTextMagenta)
	ON_COMMAND(ID_TEXT_YELLOW, &CMy8_27View::OnTextYellow)
	ON_COMMAND(ID_TEXT_USER, &CMy8_27View::OnTextUser)
END_MESSAGE_MAP()

// CMy8_27View 생성/소멸

CMy8_27View::CMy8_27View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy8_27View::~CMy8_27View()
{
}

BOOL CMy8_27View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy8_27View 그리기

void CMy8_27View::OnDraw(CDC* pDC)
{
	CMy8_27Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDC->SetTextColor(pDoc->getColor());
	pDC->TextOutA(pDoc->getPoint().x, pDoc->getPoint().y, pDoc->getString());
}


// CMy8_27View 인쇄

BOOL CMy8_27View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy8_27View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy8_27View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy8_27View 진단

#ifdef _DEBUG
void CMy8_27View::AssertValid() const
{
	CView::AssertValid();
}

void CMy8_27View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy8_27Doc* CMy8_27View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy8_27Doc)));
	return (CMy8_27Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy8_27View 메시지 처리기


void CMy8_27View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setPoint(point);

	CView::OnLButtonDown(nFlags, point);
}


void CMy8_27View::OnTextBlack()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(0, 0, 0));
}


void CMy8_27View::OnTextBlue()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(0, 0, 255));
}


void CMy8_27View::OnTextGreen()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(0, 255, 0));
}


void CMy8_27View::OnTextCyan()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(0, 255, 255));
}


void CMy8_27View::OnTextRed()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(255, 0, 0));
}


void CMy8_27View::OnTextMagenta()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(255, 0, 255));
}


void CMy8_27View::OnTextYellow()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	pDoc->setColor(RGB(255, 255, 0));
}


void CMy8_27View::OnTextUser()
{
	// TODO: Add your command handler code here
	CMy8_27Doc* pDoc = GetDocument();
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		pDoc->setColor(dlg.GetColor());
	}
}
