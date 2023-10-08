// Sheet.cpp : implementation file
//

#include "stdafx.h"
#include "11_10.h"
#include "Sheet.h"
#include "PageMy.h"
#include "PageYour.h"
#include "PageHer.h"


// CSheet

IMPLEMENT_DYNAMIC(CSheet, CPropertySheet)

CSheet::CSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_pageMy);
	AddPage(&m_pageYour);
	AddPage(&m_pageHer);
}

CSheet::CSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_pageMy);
	AddPage(&m_pageYour);
	AddPage(&m_pageHer);
}

CSheet::~CSheet()
{
}


BEGIN_MESSAGE_MAP(CSheet, CPropertySheet)
END_MESSAGE_MAP()


// CSheet message handlers
