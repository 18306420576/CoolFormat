// MyBCGPPropList.cpp : ʵ���ļ�

#include "stdafx.h"
#include "MyBCGPPropList.h"
#include "MyBCGPProp.h"

//////////////////////////////////////////////////////////////////////////
// CMyBCGPPropList

IMPLEMENT_DYNAMIC(CMyBCGPPropList, CBCGPPropList)

CMyBCGPPropList::~CMyBCGPPropList()
{
}

BEGIN_MESSAGE_MAP(CMyBCGPPropList, CBCGPPropList)
END_MESSAGE_MAP()

// CMyBCGPPropList ��Ϣ�������

void CMyBCGPPropList::SetPreviewWnd(CWnd* pWnd)
{
	m_pWndPreview = pWnd;
}

void CMyBCGPPropList::Init()
{
	CBCGPPropList::Init();
	m_pWndPreview = NULL;
}

void CMyBCGPPropList::OnChangeSelection(CBCGPProp* pNewSel, CBCGPProp* pOldSel)
{
	CBCGPPropList::OnChangeSelection(pNewSel, pOldSel);
	PreviewSelProperty(pNewSel);
}

void CMyBCGPPropList::OnPropertyChanged(CBCGPProp* pProp) const
{
	CBCGPPropList::OnPropertyChanged(pProp);
	PreviewSelProperty(pProp, TRUE);
}

void CMyBCGPPropList::PreviewSelProperty(CBCGPProp* pProp, BOOL bCheck/* = FALSE*/) const
{
	CMyBCGPProp* pMyProp = DYNAMIC_DOWNCAST(CMyBCGPProp, pProp);
	if (pMyProp == NULL || m_pWndPreview == NULL || pProp->IsGroup())
	{
		return;
	}

	if (bCheck && !(pMyProp->m_dwFlags & 0x0001))
	{
		return;
	}
	m_pWndPreview->SetWindowText(pMyProp->GetSelectedPreviewOption());
}

CBCGPProp* CMyBCGPPropList::FindItemByShort(LPCTSTR lpszShort, BOOL bSearchSubItems /*= TRUE*/) const
{
	for (POSITION pos = m_lstProps.GetHeadPosition(); pos != NULL;)
	{
		CBCGPProp* pProp = m_lstProps.GetNext(pos);
		ASSERT_VALID(pProp);

		CMyBCGPProp* pMyProp = DYNAMIC_DOWNCAST(CMyBCGPProp, pProp);
		if (pMyProp == NULL)
		{
			continue;
		}

		if (pMyProp->IsExistShort(lpszShort))
		{
			return pMyProp;
		}
		if (bSearchSubItems)
		{
			pProp = pMyProp->FindSubItemByShort(lpszShort);

			if (pProp != NULL)
			{
				ASSERT_VALID(pProp);
				return pProp;
			}
		}
	}

	return NULL;
}

void CMyBCGPPropList::GetResultShorts(CString& strValue)
{
	for (POSITION pos = m_lstProps.GetHeadPosition(); pos != NULL;)
	{
		CBCGPProp* pProp = m_lstProps.GetNext(pos);
		ASSERT_VALID(pProp);

		CMyBCGPProp* pMyProp = DYNAMIC_DOWNCAST(CMyBCGPProp, pProp);
		if (pMyProp == NULL)
		{
			continue;
		}

		pMyProp->GetResultShort(strValue);
		pMyProp->GetSubResultShorts(strValue);
	}
}


