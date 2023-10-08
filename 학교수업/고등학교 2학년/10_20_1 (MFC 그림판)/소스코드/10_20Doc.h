
// 10_20Doc.h : interface of the CMy10_20Doc class
//


#pragma once


class CMy10_20Doc : public CDocument
{
protected: // create from serialization only
	CMy10_20Doc();
	DECLARE_DYNCREATE(CMy10_20Doc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMy10_20Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	CString m_strDoc;
	afx_msg void OnDoctoView();
	afx_msg void OnDoctoMain();
	afx_msg void OnDoctoApp();
};
