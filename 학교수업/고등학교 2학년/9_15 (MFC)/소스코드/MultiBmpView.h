
// MultiBmpView.h : CMultiBmpView 클래스의 인터페이스
//

#pragma once


class CMultiBmpView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMultiBmpView();
	DECLARE_DYNCREATE(CMultiBmpView)

// 특성입니다.
public:
	CMultiBmpDoc* GetDocument() const;

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
	virtual ~CMultiBmpView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	int a;
	CDC m_mdc[6];
	CBitmap m_bit[6];
	CRect m_r[2][3];
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	int m_nSel;
	afx_msg void OnPic1();
	afx_msg void OnPic2();
	afx_msg void OnPic3();
	afx_msg void OnPic4();
	afx_msg void OnPic5();
	afx_msg void OnPic6();
	afx_msg void OnPicPrev();
	afx_msg void OnPicNext();
	afx_msg void OnPicAll();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	bool m_bAllView;
	bool m_bSel;
};

#ifndef _DEBUG  // MultiBmpView.cpp의 디버그 버전
inline CMultiBmpDoc* CMultiBmpView::GetDocument() const
   { return reinterpret_cast<CMultiBmpDoc*>(m_pDocument); }
#endif

