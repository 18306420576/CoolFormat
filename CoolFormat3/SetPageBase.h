#pragma once
#include "MyBCGPProp.h"
#include "MyBCGPPropList.h"

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
	CMyBCGPPropList m_wndPropList;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()

	virtual void InitPropList() {}
	virtual void InitTidyConfig() {}
	virtual void EndTidyConfig() {}
	virtual void SetTidyProp(LPCTSTR lpszParam, int nNumValue) {}

	virtual void SetTidyConfig(LPCTSTR lpszTidy);
	virtual void SetTidyControl(LPCTSTR lpszTidy, int nPos, int nSize);
	virtual void GetTidyConfig(CString &strTidyValue);

public:
	virtual BOOL OnInitDialog();
	virtual void OnOK();
};
