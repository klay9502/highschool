// PageMy.cpp : implementation file
//

#include "stdafx.h"
#include "11_10.h"
#include "PageMy.h"
#include "afxdialogex.h"


// CPageMy dialog

IMPLEMENT_DYNAMIC(CPageMy, CPropertyPage)

CPageMy::CPageMy()
	: CPropertyPage(CPageMy::IDD)
{

}

CPageMy::~CPageMy()
{
}

void CPageMy::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPageMy, CPropertyPage)
END_MESSAGE_MAP()


// CPageMy message handlers
