#pragma once


// CPageMy dialog

class CPageMy : public CPropertyPage
{
	DECLARE_DYNAMIC(CPageMy)

public:
	CPageMy();
	virtual ~CPageMy();

// Dialog Data
	enum { IDD = IDD_MY_PAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
