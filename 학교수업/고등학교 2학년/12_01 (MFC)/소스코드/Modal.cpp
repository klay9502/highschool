// Modal.cpp : implementation file
//

#include "stdafx.h"
#include "DialogTest.h"
#include "Modal.h"
#include "afxdialogex.h"


// CModal dialog

IMPLEMENT_DYNAMIC(CModal, CDialog)

CModal::CModal(CWnd* pParent /*=NULL*/)
	: CDialog(CModal::IDD, pParent)
{

}

CModal::~CModal()
{
}

void CModal::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CModal, CDialog)
END_MESSAGE_MAP()


// CModal message handlers
