
// 10_13View.h : interface of the CMy10_13View class
//

#pragma once
#include "atltypes.h"
enum TOOL
{
	DPEN,
	DLINE,
	DELLIPSE,
	DRECT,
	DROUNDRECT,
	DERASE,
	DFILL
};

#define BLACK RGB(0, 0, 0)
#define BLUE RGB(0, 0, 255)
#define GREEN RGB(0, 255, 0)
#define CYAN RGB(0, 255, 255)
#define RED RGB(255, 0, 0)
#define MAGENTA RGB(255, 0, 255)
#define YELLOW RGB(255, 255, 0)
#define WHITE RGB(255, 255, 255)


class CMy10_13View : public CView
{
protected: // create from serialization only
	CMy10_13View();
	DECLARE_DYNCREATE(CMy10_13View)

// Attributes
public:
	CMy10_13Doc* GetDocument() const;

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
	virtual ~CMy10_13View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	COLORREF m_crPen;
	COLORREF m_crBr;
	int m_nTool;
	int m_nWidth;
	BOOL m_bIsDraw;
	CPoint m_ptStart;
	CPoint m_ptOld;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnColorsBlack();
	afx_msg void OnColorsBlue();
	afx_msg void OnColorsGreen();
	afx_msg void OnColorsCyan();
	afx_msg void OnColorsRed();
	afx_msg void OnColorsMagenta();
	afx_msg void OnColorsYellow();
	afx_msg void OnColorsUser();
	afx_msg void OnWidth1();
	afx_msg void OnWidth2();
	afx_msg void OnWidth3();
	afx_msg void OnWidth5();
	afx_msg void OnWidth10();
	afx_msg void OnToolPen();
	afx_msg void OnToolLine();
	afx_msg void OnToolEllipse();
	afx_msg void OnToolRect();
	afx_msg void OnToolRoundrect();
	afx_msg void OnToolErase();
	afx_msg void OnToolFill();
	afx_msg void OnBrushBlack();
	afx_msg void OnBrushBlue();
	afx_msg void OnBrushGreen();
	afx_msg void OnBrushCyan();
	afx_msg void OnBrushRed();
	afx_msg void OnBrushMagenta();
	afx_msg void OnBrushYellow();
	afx_msg void OnBrushWhite();
	afx_msg void OnBrushUser();
	afx_msg void OnUpdateColorsBlack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorsBlue(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorsGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorsCyan(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorsRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorsMagenta(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorsYellow(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorsUser(CCmdUI *pCmdUI);
	int m_nPenCheak;
	int m_nWidthCheak;
	afx_msg void OnUpdateWidth1(CCmdUI *pCmdUI);
	afx_msg void OnUpdateWidth2(CCmdUI *pCmdUI);
	afx_msg void OnUpdateWidth3(CCmdUI *pCmdUI);
	afx_msg void OnUpdateWidth5(CCmdUI *pCmdUI);
	afx_msg void OnUpdateWidth10(CCmdUI *pCmdUI);
	afx_msg void OnUpdateToolPen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateToolLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateToolEllipse(CCmdUI *pCmdUI);
	afx_msg void OnUpdateToolRect(CCmdUI *pCmdUI);
	afx_msg void OnUpdateToolRoundrect(CCmdUI *pCmdUI);
	afx_msg void OnUpdateToolErase(CCmdUI *pCmdUI);
	afx_msg void OnUpdateToolFill(CCmdUI *pCmdUI);
	int m_nToolCheak;
	afx_msg void OnUpdateBrushBlack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushBlue(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushCyan(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushMagenta(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushYellow(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushWhite(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushUser(CCmdUI *pCmdUI);
	int m_nBrushCheak;
	HCURSOR hPen, hLine, hEllipse, hRect, hRoundRect, hFill;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};

#ifndef _DEBUG  // debug version in 10_13View.cpp
inline CMy10_13Doc* CMy10_13View::GetDocument() const
   { return reinterpret_cast<CMy10_13Doc*>(m_pDocument); }
#endif

