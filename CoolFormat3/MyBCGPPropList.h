/**
* @file MyBCGPPropList.h
* @brief ��չCBCGPPropListʵ��ѡ��ı��¼�
* @author �޻�
* @date 2014-12-11
* @details
*/
#pragma once

//////////////////////////////////////////////////////////////////////////
// CMyBCGPPropList

class CMyBCGPPropList : public CBCGPPropList
{
	DECLARE_DYNAMIC(CMyBCGPPropList)

public:
	virtual ~CMyBCGPPropList();

	void SetPreviewWnd(CWnd* pWnd);

	CBCGPProp* FindItemByShort(LPCTSTR lpszShort, BOOL bSearchSubItems = TRUE) const;

	void GetResultShorts(CString& strValue);

protected:
	DECLARE_MESSAGE_MAP()

	void Init();
	void OnChangeSelection(CBCGPProp* /*pNewSel*/, CBCGPProp* /*pOldSel*/);
	void OnPropertyChanged(CBCGPProp* pProp) const;

	void PreviewSelProperty(CBCGPProp* pProp, BOOL bCheck = FALSE) const;

protected:
	CWnd* m_pWndPreview;
};


