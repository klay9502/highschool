// PageYour.cpp : implementation file
//

#include "stdafx.h"
#include "11_10.h"
#include "PageYour.h"
#include "afxdialogex.h"


// CPageYour dialog

IMPLEMENT_DYNAMIC(CPageYour, CPropertyPage)

CPageYour::CPageYour()
	: CPropertyPage(CPageYour::IDD)
{

}

CPageYour::~CPageYour()
{
}

void CPageYour::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPageYour, CPropertyPage)
END_MESSAGE_MAP()


// CPageYour message handlers
