#pragma once
#include "SetPageBase.h"

//////////////////////////////////////////////////////////////////////////
// CSetPageCpp �Ի���

class CSetPageCpp : public CSetPageBase
{
public:
	CSetPageCpp(LPCTSTR lpszTitle, CString& strTidy);
	virtual ~CSetPageCpp();

protected:
	void InitPropList();
};
