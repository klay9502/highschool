// Modaless.cpp : implementation file
//

#include "stdafx.h"
#include "DialogTest.h"
#include "Modaless.h"
#include "afxdialogex.h"


// CModaless dialog

IMPLEMENT_DYNAMIC(CModaless, CDialog)

CModaless::CModaless(CWnd* pParent /*=NULL*/)
	: CDialog(CModaless::IDD, pParent)
{

}

CModaless::~CModaless()
{
}

void CModaless::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CModaless, CDialog)
	ON_BN_CLICKED(IDOK, &CModaless::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CModaless::OnBnClickedCancel)
END_MESSAGE_MAP()


// CModaless message handlers


void CModaless::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	this->DestroyWindow();
	//CDialog::OnOK();
}


void CModaless::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	this->DestroyWindow();
	//CDialog::OnCancel();
}
