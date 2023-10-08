#pragma once


// CUnitTable dialog

class CUnitTable : public CDialog
{
	DECLARE_DYNAMIC(CUnitTable)

public:
	CUnitTable(CWnd* pParent = NULL);   // standard constructor
	virtual ~CUnitTable();

// Dialog Data
	enum { IDD = IDD_TABLE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
