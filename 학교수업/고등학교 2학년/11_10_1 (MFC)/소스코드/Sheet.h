#pragma once
#include "PageMy.h"
#include "PageYour.h"
#include "PageHer.h"



// CSheet

class CSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSheet)

public:
	CSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CSheet();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CPageMy m_pageMy;
	CPageYour m_pageYour;
	CPageHer m_pageHer;
};


