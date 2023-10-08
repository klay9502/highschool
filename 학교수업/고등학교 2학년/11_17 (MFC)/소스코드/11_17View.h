
// 11_17View.h : interface of the CMy11_17View class
//

#pragma once


class CMy11_17View : public CView
{
protected: // create from serialization only
	CMy11_17View();
	DECLARE_DYNCREATE(CMy11_17View)

// Attributes
public:
	CMy11_17Doc* GetDocument() const;

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
	virtual ~CMy11_17View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in 11_17View.cpp
inline CMy11_17Doc* CMy11_17View::GetDocument() const
   { return reinterpret_cast<CMy11_17Doc*>(m_pDocument); }
#endif

