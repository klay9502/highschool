
// 10_22View.h : interface of the CMy10_22View class
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class CMy10_22View : public CFormView
{
protected: // create from serialization only
	CMy10_22View();
	DECLARE_DYNCREATE(CMy10_22View)

public:
	enum{ IDD = IDD_MY10_22_FORM };

// Attributes
public:
	CMy10_22Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct

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
	int m_nCount;
	CListBox m_ctrList;
	CString m_strName;
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonAdd();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnLbnDblclkListName();
	afx_msg void OnBnClickedButtonFind();
	afx_msg void OnBnClickedButtonInsert();
	afx_msg void OnBnClickedButtonEdit();
};

#ifndef _DEBUG  // debug version in 10_22View.cpp
inline CMy10_22Doc* CMy10_22View::GetDocument() const
   { return reinterpret_cast<CMy10_22Doc*>(m_pDocument); }
#endif

