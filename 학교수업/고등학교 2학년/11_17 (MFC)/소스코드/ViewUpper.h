#pragma once


// CViewUpper view

class CViewUpper : public CView
{
	DECLARE_DYNCREATE(CViewUpper)

protected:
	CViewUpper();           // protected constructor used by dynamic creation
	virtual ~CViewUpper();

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


