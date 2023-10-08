
// 9_03View.h : interface of the CMy9_03View class
//

#pragma once


class CMy9_03View : public CView
{
protected: // create from serialization only
	CMy9_03View();
	DECLARE_DYNCREATE(CMy9_03View)

// Attributes
public:
	CMy9_03Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMy9_03View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	int nX, nY;		// 원의 중심, x와 y좌표
	int nMx, nMy;	// 축의 이동 방향과 폭
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // debug version in 9_03View.cpp
inline CMy9_03Doc* CMy9_03View::GetDocument() const
   { return reinterpret_cast<CMy9_03Doc*>(m_pDocument); }
#endif

