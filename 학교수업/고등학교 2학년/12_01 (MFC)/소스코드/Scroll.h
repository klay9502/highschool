#pragma once
#include "afxwin.h"


// CScroll dialog

class CScroll : public CDialog
{
	DECLARE_DYNAMIC(CScroll)

public:
	CScroll(CWnd* pParent = NULL);   // standard constructor
	virtual ~CScroll();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_red;
	int m_green;
	int m_blue;
	CScrollBar m_scrRed;
	CScrollBar m_scrGreen;
	CScrollBar m_scrBlue;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
