
// 8_25View.h : CMy8_25View 클래스의 인터페이스
//

#pragma once


class CMy8_25View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy8_25View();
	DECLARE_DYNCREATE(CMy8_25View)

// 특성입니다.
public:
	CMy8_25Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy8_25View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	int m_n; // 홀, 짝을 저장하기 위한 변수
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 8_25View.cpp의 디버그 버전
inline CMy8_25Doc* CMy8_25View::GetDocument() const
   { return reinterpret_cast<CMy8_25Doc*>(m_pDocument); }
#endif

