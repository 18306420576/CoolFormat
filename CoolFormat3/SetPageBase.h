#pragma once

//////////////////////////////////////////////////////////////////////////
// CSetPageBase �Ի���

class CSetPageBase : public CBCGPPropertyPage
{
	DECLARE_DYNAMIC(CSetPageBase)

public:
	CSetPageBase();
	virtual ~CSetPageBase();

// �Ի�������
	enum { IDD = IDD_SET_BASE };

protected:
	CBCGPPropList m_wndPropList;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	void SetViewEdit(LPCTSTR lpszText);

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
