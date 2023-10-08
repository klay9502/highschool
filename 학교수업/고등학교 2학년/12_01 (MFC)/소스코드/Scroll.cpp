// Scroll.cpp : implementation file
//

#include "stdafx.h"
#include "DialogTest.h"
#include "Scroll.h"
#include "afxdialogex.h"


// CScroll dialog

IMPLEMENT_DYNAMIC(CScroll, CDialog)

CScroll::CScroll(CWnd* pParent /*=NULL*/)
	: CDialog(CScroll::IDD, pParent)
	, m_red(255)
	, m_green(0)
	, m_blue(0)
{

}

CScroll::~CScroll()
{
}

void CScroll::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RED, m_red);
	DDX_Text(pDX, IDC_EDIT_GREEN, m_green);
	DDX_Text(pDX, IDC_EDIT_BLUE, m_blue);
	DDX_Control(pDX, IDC_SCR_RED, m_scrRed);
	DDX_Control(pDX, IDC_SCR_GREEN, m_scrGreen);
	DDX_Control(pDX, IDC_SCR_BLUE, m_scrBlue);
}


BEGIN_MESSAGE_MAP(CScroll, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CScroll message handlers


BOOL CScroll::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	m_scrRed.SetScrollRange(0, 255);
	m_scrGreen.SetScrollRange(0, 255);
	m_scrBlue.SetScrollRange(0, 255);

	m_scrRed.SetScrollPos(m_red);
	m_scrGreen.SetScrollPos(m_green);
	m_scrBlue.SetScrollPos(m_blue);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CScroll::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialog::OnPaint() for painting messages
	CBrush brush, *pOldB;
	brush.CreateSolidBrush(RGB(m_red, m_green, m_blue));
	pOldB = dc.SelectObject(&brush);
	dc.RoundRect(300, 350, 550, 450, 20, 20);
	dc.SelectObject(pOldB);
}
