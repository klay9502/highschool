#pragma once


// CModaless dialog

class CModaless : public CDialog
{
	DECLARE_DYNAMIC(CModaless)

public:
	CModaless(CWnd* pParent = NULL);   // standard constructor
	virtual ~CModaless();

// Dialog Data
	enum { IDD = IDD_MODALESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
