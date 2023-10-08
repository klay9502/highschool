
// 9_17View.h : interface of the CMy9_17View class
//

#pragma once


class CMy9_17View : public CView
{
protected: // create from serialization only
	CMy9_17View();
	DECLARE_DYNCREATE(CMy9_17View)

// Attributes
public:
	CMy9_17Doc* GetDocument() const;

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
	virtual ~CMy9_17View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCursorXbox();
	afx_msg void OnCursorBall();
	afx_msg void OnCursorHi();
	afx_msg void OnCursorPencil();
	int m_nCursor;
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};

#ifndef _DEBUG  // debug version in 9_17View.cpp
inline CMy9_17Doc* CMy9_17View::GetDocument() const
   { return reinterpret_cast<CMy9_17Doc*>(m_pDocument); }
#endif

