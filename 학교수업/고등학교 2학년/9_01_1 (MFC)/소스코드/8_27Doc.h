
// 8_27Doc.h : CMy8_27Doc 클래스의 인터페이스
//


#pragma once
#include "atltypes.h"


class CMy8_27Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CMy8_27Doc();
	DECLARE_DYNCREATE(CMy8_27Doc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CMy8_27Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
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
