#pragma once
#include "SetPageBase.h"

//////////////////////////////////////////////////////////////////////////
// CSetPageJson �Ի���

class CSetPageJson : public CSetPageBase
{
public:
	CSetPageJson();
	virtual ~CSetPageJson();

protected:
	void InitPropList();
	void InitTidyConfig();
	void EndTidyConfig();
	void SetTidyProp(LPCTSTR lpszParam, int nNumValue);
};
