#pragma once


// CViewCount view

class CViewCount : public CView
{
	DECLARE_DYNCREATE(CViewCount)

protected:
	CViewCount();           // protected constructor used by dynamic creation
	virtual ~CViewCount();

public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	CMy11_17Doc* GetDocument() const;
};


