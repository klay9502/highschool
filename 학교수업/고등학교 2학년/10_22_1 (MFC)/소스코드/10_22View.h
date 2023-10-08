
// 10_22View.h : interface of the CMy10_22View class
//

#pragma once


class CMy10_22View : public CView
{
protected: // create from serialization only
	CMy10_22View();
	DECLARE_DYNCREATE(CMy10_22View)

// Attributes
public:
	CMy10_22Doc* GetDocument() const;

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
	virtual ~CMy10_22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDialogShow();
};

#ifndef _DEBUG  // debug version in 10_22View.cpp
inline CMy10_22Doc* CMy10_22View::GetDocument() const
   { return reinterpret_cast<CMy10_22Doc*>(m_pDocument); }
#endif

