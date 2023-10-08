#pragma once


// CPageHer dialog

class CPageHer : public CPropertyPage
{
	DECLARE_DYNAMIC(CPageHer)

public:
	CPageHer();
	virtual ~CPageHer();

// Dialog Data
	enum { IDD = IDD_HER_PAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_strText;
};
