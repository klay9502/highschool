
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
	ON_WM_MOUSEMOVE()
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
	CString str = pDoc->getString();
	CPoint pt = pDoc->getPoint();
	pDC->TextOutA(pt.x, pt.y, str);
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


//void CMy8_27View::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: Add your message handler code here and/or call default
//	CMy8_27Doc* pDoc = GetDocument();
//	pDoc->setPoint(point);
//	CString str;
//	str.Format("현재좌표[%d][%d]", point.x, point.y);
//	pDoc->setString(str);
//	Invalidate();
//
//	CView::OnLButtonDown(nFlags, point);
//}


void CMy8_27View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy8_27Doc* pDoc = GetDocument();
	CString str;
	str.Format("현재좌표[%d][%d]", point.x, point.y);
	pDoc->setString(str);
	Invalidate();


	CView::OnMouseMove(nFlags, point);
}
