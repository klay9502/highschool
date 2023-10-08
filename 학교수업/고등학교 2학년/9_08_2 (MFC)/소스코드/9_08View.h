
// 9_08View.h : interface of the CMy9_08View class
//

#pragma once


class CMy9_08View : public CView
{
protected: // create from serialization only
	CMy9_08View();
	DECLARE_DYNCREATE(CMy9_08View)

// Attributes
public:
	CMy9_08Doc* GetDocument() const;

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
	virtual ~CMy9_08View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 9_08View.cpp
inline CMy9_08Doc* CMy9_08View::GetDocument() const
   { return reinterpret_cast<CMy9_08Doc*>(m_pDocument); }
#endif

