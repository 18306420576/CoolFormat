#pragma once
#include "SetPageBase.h"

//////////////////////////////////////////////////////////////////////////
// CSetPageSql �Ի���

class CSetPageSql : public CSetPageBase
{
public:
	CSetPageSql(LPCTSTR lpszTitle, CString& strTidy);
	virtual ~CSetPageSql();

protected:
	void InitPropList();
};
