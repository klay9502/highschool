
// 10_22View.cpp : implementation of the CMy10_22View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "10_22.h"
#endif

#include "10_22Doc.h"
#include "10_22View.h"
#include "ModDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy10_22View

IMPLEMENT_DYNCREATE(CMy10_22View, CFormView)

BEGIN_MESSAGE_MAP(CMy10_22View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CMy10_22View::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMy10_22View::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CMy10_22View::OnBnClickedButtonDelete)
	ON_LBN_DBLCLK(IDC_LIST_NAME, &CMy10_22View::OnLbnDblclkListName)
	ON_BN_CLICKED(IDC_BUTTON_FIND, &CMy10_22View::OnBnClickedButtonFind)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CMy10_22View::OnBnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &CMy10_22View::OnBnClickedButtonEdit)
END_MESSAGE_MAP()

// CMy10_22View construction/destruction

CMy10_22View::CMy10_22View()
	: CFormView(CMy10_22View::IDD)
	, m_nCount(0)
	, m_strName(_T(""))
{
	// TODO: add construction code here

}

CMy10_22View::~CMy10_22View()
{
}

void CMy10_22View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_COUNT, m_nCount);
	DDX_Control(pDX, IDC_LIST_NAME, m_ctrList);
	DDX_Text(pDX, IDC_NAME, m_strName);
}

BOOL CMy10_22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMy10_22View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMy10_22View diagnostics

#ifdef _DEBUG
void CMy10_22View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy10_22View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy10_22Doc* CMy10_22View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy10_22Doc)));
	return (CMy10_22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy10_22View message handlers


void CMy10_22View::OnBnClickedButtonClear()
{
	// TODO: Add your control notification handler code here
	m_strName = "";
	// 공백은 쌍따옴표를 붙여서 만든다. 공백을 넣으면 안됌.
	UpdateData(FALSE); // Value형 변수에 있는 데이터를 컨트롤에 나타냄.
	GetDlgItem(IDC_NAME)->SetFocus();
}


void CMy10_22View::OnBnClickedButtonAdd()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);	// 컨트롤에 있는 데이터를 Value형 변수로 입력

	if (m_strName == "")
	{
		MessageBox("자료 입력!");
		OnBnClickedButtonClear(); // 위의 함수 다시 호출
		return;
	}

	int nFind = m_ctrList.FindStringExact(-1, m_strName);

	if (nFind != LB_ERR)
	{
		MessageBox("'" + m_strName + "'" + "은 이미 있습니다!");
		OnBnClickedButtonClear(); // 위의 함수 다시 호출
		return;
	}

	m_ctrList.AddString(m_strName);
	m_nCount = m_ctrList.GetCount();
	OnBnClickedButtonClear(); // 위의 함수 다시 호출
}


BOOL CMy10_22View::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		if (GetFocus() == GetDlgItem(IDC_NAME))
		{
			OnBnClickedButtonAdd();
		}
	}

	return CFormView::PreTranslateMessage(pMsg);
}


void CMy10_22View::OnBnClickedButtonDelete()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);	// 컨트롤에 있는 데이터를 Value형 변수로 입력

	if (m_strName == "")
	{
		MessageBox("자료 입력!");
		OnBnClickedButtonClear(); // 위의 함수 다시 호출
		return;
	}

	int nFind = m_ctrList.FindStringExact(-1, m_strName);

	if (nFind == LB_ERR)
	{
		MessageBox("'" + m_strName + "'" + "은 없는 데이터입니다!");
		OnBnClickedButtonClear(); // 위의 함수 다시 호출
		return;
	}

	m_ctrList.DeleteString(nFind);
	m_nCount = m_ctrList.GetCount();
	OnBnClickedButtonClear(); // 위의 함수 다시 호출
}


void CMy10_22View::OnLbnDblclkListName()
{
	// TODO: Add your control notification handler code here
	int nSel = m_ctrList.GetCurSel();
	m_ctrList.GetText(nSel, m_strName);
	UpdateData(FALSE);
}


void CMy10_22View::OnBnClickedButtonFind()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);	// 컨트롤에 있는 데이터를 Value형 변수로 입력

	if (m_strName == "")
	{
		MessageBox("자료 입력!");
		OnBnClickedButtonClear(); // 위의 함수 다시 호출
		return;
	}

	int nFind = m_ctrList.FindStringExact(-1, m_strName);

	if (nFind == LB_ERR)
	{
		MessageBox("'" + m_strName + "'" + "은 없는 데이터입니다!");
		OnBnClickedButtonClear(); // 위의 함수 다시 호출
		return;
	}

	m_ctrList.SetCurSel(nFind);
	OnBnClickedButtonClear(); // 위의 함수 다시 호출
}


void CMy10_22View::OnBnClickedButtonInsert()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);	// 컨트롤에 있는 데이터를 Value형 변수로 입력

	if (m_strName == "")
	{
		MessageBox("자료 입력!");
		OnBnClickedButtonClear(); // 위의 함수 다시 호출
		return;
	}

	int nFind = m_ctrList.FindStringExact(-1, m_strName);

	if (nFind != LB_ERR)
	{
		MessageBox("'" + m_strName + "'" + "은 이미 있습니다!");
		OnBnClickedButtonClear(); // 위의 함수 다시 호출
		return;
	}

	int nSel = m_ctrList.GetCurSel();

	if (nSel == LB_ERR)
	{
		MessageBox("삽입할 곳 선택!");
		return;
	}

	m_ctrList.InsertString(nSel, m_strName);
	m_nCount = m_ctrList.GetCount();
	m_ctrList.SetCurSel(nSel);
	OnBnClickedButtonClear(); // 위의 함수 다시 호출
}


void CMy10_22View::OnBnClickedButtonEdit()
{
	// TODO: Add your control notification handler code here
	CModDlg dlg;
	int nSel = m_ctrList.GetCurSel();

	if (nSel == LB_ERR)
	{
		MessageBox("수정항목 선택!");
		return;
	}

	m_ctrList.GetText(nSel, dlg.m_strName);

	if (dlg.DoModal() == IDOK)
	{
		m_ctrList.DeleteString(nSel);
		m_ctrList.InsertString(nSel, dlg.m_strName);
	}
}
