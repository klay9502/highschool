
// 8_27Doc.h : CMy8_27Doc Ŭ������ �������̽�
//


#pragma once
#include "atltypes.h"


class CMy8_27Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CMy8_27Doc();
	DECLARE_DYNCREATE(CMy8_27Doc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CMy8_27Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	CPoint m_pt;
	CString m_str;
	COLORREF m_cr;
	void setString(CString _str);
	void setPoint(CPoint _pt);
	void setColor(COLORREF _cr);
	CString getString();
	CPoint getPoint();
	COLORREF getColor();
};
