	#pragma once


// CModal dialog

class CModal : public CDialog
{
	DECLARE_DYNAMIC(CModal)

public:
	CModal(CWnd* pParent = NULL);   // standard constructor
	virtual ~CModal();

// Dialog Data
	enum { IDD = IDD_MODAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
