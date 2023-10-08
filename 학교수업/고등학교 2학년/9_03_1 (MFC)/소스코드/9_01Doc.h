
// 9_01Doc.h : interface of the CMy9_01Doc class
//


#pragma once
#include "atltypes.h"


class CMy9_01Doc : public CDocument
{
protected: // create from serialization only
	CMy9_01Doc();
	DECLARE_DYNCREATE(CMy9_01Doc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMy9_01Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	CPoint m_pt;
	CSize m_sz;
	COLORREF m_cr;
	void SetPoint(CPoint _pt);
	void SetSize(CSize _size);
	void SetColor(COLORREF _color);
	CPoint GetPoint();
	CSize GetSize();
	COLORREF GetColor();
};
