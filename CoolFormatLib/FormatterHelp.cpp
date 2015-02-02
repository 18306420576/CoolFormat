#include "StdAfx.h"
#include "FormatterHelp.h"
#include "CFCssTidy.h"
#include "CFSqlTidy.h"
#include "CFJsonTidy.h"
#include "CFJsTidy.h"
#include "CFPhpTidy.h"
#include "CFHtmlTidy.h"
#include "CFCppTidy.h"
#include "SynLanguage.h"
#include "GlobalTidy.h"

#ifdef _DEBUG
#pragma comment(lib, "CssTidyLibd.lib")
#pragma comment(lib, "SqlFormatterLibd.lib")
#pragma comment(lib, "JsonCppLibd.lib")
#pragma comment(lib, "JsFormatterLibd.lib")
#pragma comment(lib, "PhpFormatterLibd.lib")
#pragma comment(lib, "tidylibd.lib")
#pragma comment(lib, "AStyleLibd.lib")
#else
#pragma comment(lib, "CssTidyLib.lib")
#pragma comment(lib, "SqlFormatterLib.lib")
#pragma comment(lib, "JsonCppLib.lib")
#pragma comment(lib, "JsFormatterLib.lib")
#pragma comment(lib, "PhpFormatterLib.lib")
#pragma comment(lib, "tidylib.lib")
#pragma comment(lib, "AStyleLib.lib")
#endif // _DEBUG

CFormatterHelp::CFormatterHelp(void)
{
}

CFormatterHelp::~CFormatterHelp(void)
{
}

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to)
{
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
	}
	return str;
}

bool CFormatterHelp::DoFormatter(unsigned int nLanguage, const std::string &strTextIn, std::string &strTextOut, std::string &strMsgOut, unsigned int uCodepage)
{
	CCFBaseTidy* pTidy = NULL;
	std::string strTidy;
	
	switch (nLanguage)
	{
	case SYN_CPP:
	{
		pTidy = new CCFCppTidy();
		std::string strNewTidy(g_GlobalTidy.m_TidyCpp);
		strNewTidy = ReplaceAll(strNewTidy, "-", " -");
		strTidy = (strNewTidy);
		strTidy.append(" --mode=c");
	}
	break;
	case SYN_CS:
	{
		pTidy = new CCFCppTidy();
		std::string strNewTidy(g_GlobalTidy.m_TidyCSharp);
		strNewTidy = ReplaceAll(strNewTidy, "-", " -");
		strTidy = (strNewTidy);
		strTidy.append(" --mode=cs");
	}
	break;
	case SYN_JAVA:
	{
		pTidy = new CCFCppTidy();
		std::string strNewTidy(g_GlobalTidy.m_TidyJava);
		strNewTidy = ReplaceAll(strNewTidy, "-", " -");
		strTidy = (strNewTidy);
		strTidy.append(" --mode=java");
	}
	break;
	case SYN_OBJECTIVEC:
	{
		pTidy = new CCFCppTidy();
		std::string strNewTidy(g_GlobalTidy.m_TidyObjectiveC);
		strNewTidy = ReplaceAll(strNewTidy, "-", " -");
		strTidy = (strNewTidy);
		strTidy.append(" --mode=c");
	}
	break;
	case SYN_HTML:
	{
		pTidy = new CCFHtmlTidy();
		strTidy = (g_GlobalTidy.m_TidyHtml);
	}
	break;
	case SYN_XML:
	{
		pTidy = new CCFHtmlTidy();
		strTidy = (g_GlobalTidy.m_TidyXml);
	}
	break;
	case SYN_PHP:
	{
		pTidy = new CCFPhpTidy();
		strTidy = (g_GlobalTidy.m_TidyPhp);
	}
	break;
	case SYN_JAVASCRIPT:
	{
		pTidy = new CCFJsTidy();
		strTidy = (g_GlobalTidy.m_TidyJs);
	}
	break;
	case SYN_CSS:
	{
		pTidy = new CCFCssTidy();
		strTidy = (g_GlobalTidy.m_TidyCss);
	}
	break;
	case SYN_JSON:
	{
		pTidy = new CCFJsonTidy();
		strTidy = (g_GlobalTidy.m_TidyJson);
	}
	break;
	case SYN_SQL:
	{
		pTidy = new CCFSqlTidy();
		strTidy = (g_GlobalTidy.m_TidySql);
	}
	break;
	default:
		return FALSE;
	}
		
	std::string strOut, strErr;
	bool bTidyOk = pTidy->TidyMain(strTextIn.c_str(), strTidy.c_str(), strOut, strErr);
	strTextOut = strOut;
	strMsgOut = strErr.c_str();
	delete pTidy;
	return bTidyOk;
}
