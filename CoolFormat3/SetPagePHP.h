#pragma once
#include "SetPageBase.h"

//////////////////////////////////////////////////////////////////////////
// CSetPagePHP �Ի���

class CSetPagePHP : public CSetPageBase
{
public:
	CSetPagePHP(LPCTSTR lpszTitle, CString& strTidy);
	virtual ~CSetPagePHP();

protected:
	void InitPropList();
};
