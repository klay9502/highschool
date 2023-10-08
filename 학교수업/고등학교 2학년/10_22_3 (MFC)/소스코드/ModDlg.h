#pragma once


// CModDlg dialog

class CModDlg : public CDialog
{
	DECLARE_DYNAMIC(CModDlg)

public:
	CModDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CModDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_MOD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
};
