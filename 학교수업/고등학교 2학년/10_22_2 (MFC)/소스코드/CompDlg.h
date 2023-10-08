#pragma once
#include "afxwin.h"


// CCompDlg dialog

class CCompDlg : public CDialog
{
	DECLARE_DYNAMIC(CCompDlg)

public:
	CCompDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCompDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_ctrList;
	CString m_strList;
	CComboBox m_ctrCombo;
	CString m_strName;
	int m_nSex;
	CButton m_ctrR3;
	CButton m_ctrR4;
	afx_msg void OnLbnSelchangeListCompany();
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboCompany();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
};
