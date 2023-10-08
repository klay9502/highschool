
// 8_20View.h : CMy8_20View 클래스의 인터페이스
//

#pragma once


class CMy8_20View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy8_20View();
	DECLARE_DYNCREATE(CMy8_20View)

// 특성입니다.
public:
	CMy8_20Doc* GetDocument() const;

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
	virtual ~CMy8_20View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTeacher1();
	afx_msg void OnStudent1();
	afx_msg void OnTeacher2();
	afx_msg void OnStudent2();
	afx_msg void OnTeacher3();
	afx_msg void OnStudent3();
};

#ifndef _DEBUG  // 8_20View.cpp의 디버그 버전
inline CMy8_20Doc* CMy8_20View::GetDocument() const
   { return reinterpret_cast<CMy8_20Doc*>(m_pDocument); }
#endif

