#pragma once


// CPageYour dialog

class CPageYour : public CPropertyPage
{
	DECLARE_DYNAMIC(CPageYour)

public:
	CPageYour();
	virtual ~CPageYour();

// Dialog Data
	enum { IDD = IDD_YOUR_PAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
