#pragma once
#include "SetPageBase.h"

//////////////////////////////////////////////////////////////////////////
// CSetPageJson �Ի���

class CSetPageJson : public CSetPageBase
{
public:
	CSetPageJson(LPCTSTR lpszTitle, CString& strTidy);
	virtual ~CSetPageJson();

protected:
	void InitPropList();
};
