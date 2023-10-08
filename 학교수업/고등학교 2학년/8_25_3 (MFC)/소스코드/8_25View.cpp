
// 8_25View.cpp : CMy8_25View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "8_25.h"
#endif

#include "8_25Doc.h"
#include "8_25View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy8_25View

IMPLEMENT_DYNCREATE(CMy8_25View, CView)

BEGIN_MESSAGE_MAP(CMy8_25View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMy8_25View 생성/소멸

CMy8_25View::CMy8_25View()
: m_ch(0)
, m_pt(0)
, m_value(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy8_25View::~CMy8_25View()
{
}

BOOL CMy8_25View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy8_25View 그리기

void CMy8_25View::OnDraw(CDC* pDC)
{
	CMy8_25Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	m_ch = (rand() % 26) + 'A'; // 대문자를 랜덤으로 선택
	m_pt.x = rand() & m_rect.Width(); // x 좌표를 랜덤으로 선택
	m_pt.y = rand() & m_rect.Height(); // y 좌표를 랜덤으로 선택

	CString str;
	str.Format("%c", m_ch);
	pDC->TextOutA(m_pt.x, m_pt.y, str);

	str.Format("점수 = %d", m_value);
	pDC->TextOutA(m_rect.Width() / 2 - 20, 0, str);

	SetTimer(1, 500, NULL);
}


// CMy8_25View 인쇄

BOOL CMy8_25View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy8_25View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy8_25View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy8_25View 진단

#ifdef _DEBUG
void CMy8_25View::AssertValid() const
{
	CView::AssertValid();
}

void CMy8_25View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy8_25Doc* CMy8_25View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy8_25Doc)));
	return (CMy8_25Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy8_25View 메시지 처리기


void CMy8_25View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	GetClientRect(&m_rect);
}


int CMy8_25View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	srand((unsigned)time(NULL));

	return 0;
}


void CMy8_25View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);

	dc.TextOutA(m_pt.x, m_pt.y, "    "); // 이전의 문자를 지워준다.

	m_pt.y += 20; // y좌표를 증가시킨다.

	CString str;
	str.Format("%c", m_ch); // 문자를 문자열 형태로 변환.
	dc.TextOutA(m_pt.x, m_pt.y, str); // 바뀐 문자열을 출력.

	if (m_pt.y >= m_rect.bottom)
	{
		KillTimer(1);
		if (MessageBox("한번 더 할까요?", "게임끝", MB_ICONQUESTION | MB_YESNO) == IDYES)
		{
			Invalidate();
			m_value = 0;
		}
		else
		{
			PostQuitMessage(0);
		}
	}

	CView::OnTimer(nIDEvent);
}


void CMy8_25View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	if (m_ch == nChar)
	{
		m_value++;
		Invalidate();
	}

	CView::OnChar(nChar, nRepCnt, nFlags);
}
