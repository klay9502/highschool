
// 8_20View.cpp : CMy8_20View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "8_20.h"
#endif

#include "8_20Doc.h"
#include "8_20View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy8_20View

IMPLEMENT_DYNCREATE(CMy8_20View, CView)

BEGIN_MESSAGE_MAP(CMy8_20View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_TEACHER1, &CMy8_20View::OnTeacher1)
	ON_COMMAND(ID_STUDENT1, &CMy8_20View::OnStudent1)
	ON_COMMAND(ID_TEACHER2, &CMy8_20View::OnTeacher2)
	ON_COMMAND(ID_STUDENT2, &CMy8_20View::OnStudent2)
	ON_COMMAND(ID_TEACHER3, &CMy8_20View::OnTeacher3)
	ON_COMMAND(ID_STUDENT3, &CMy8_20View::OnStudent3)
END_MESSAGE_MAP()

// CMy8_20View 생성/소멸

CMy8_20View::CMy8_20View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy8_20View::~CMy8_20View()
{
}

BOOL CMy8_20View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy8_20View 그리기

void CMy8_20View::OnDraw(CDC* /*pDC*/)
{
	CMy8_20Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy8_20View 인쇄

BOOL CMy8_20View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy8_20View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy8_20View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy8_20View 진단

#ifdef _DEBUG
void CMy8_20View::AssertValid() const
{
	CView::AssertValid();
}

void CMy8_20View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy8_20Doc* CMy8_20View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy8_20Doc)));
	return (CMy8_20Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy8_20View 메시지 처리기


void CMy8_20View::OnTeacher1()
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	dc.TextOutA(100, 50, "1학년 담임 황은순 선생님");
}


void CMy8_20View::OnStudent1()
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	dc.TextOutA(100, 100, "1학년 반장 이민규");
}


void CMy8_20View::OnTeacher2()
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	dc.TextOutA(100, 250, "2학년 담임 유명수 선생님");
}


void CMy8_20View::OnStudent2()
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	dc.TextOutA(100, 300, "2학년 반장 이윤제");
}


void CMy8_20View::OnTeacher3()
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	dc.TextOutA(100, 450, "3학년 담임 조도재 선생님");
}


void CMy8_20View::OnStudent3()
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	dc.TextOutA(100, 500, "3학년 반장 이영준");
}
