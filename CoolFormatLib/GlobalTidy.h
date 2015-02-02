#pragma once
#include <string>
#include "SynLanguage.h"

struct TidyDeafult {
	const TCHAR *langName;	//����дע���չ���û�������
	const char *tidyName;	//Ĭ�ϸ�ʽ������
	unsigned int langID;			//����ö��
};

class GlobalTidy
{
public:
	GlobalTidy(void);
	~GlobalTidy(void);
	
	/**
	 * ��ʼ��ȫ�ָ�ʽ������
	 * @return void 
	 */
	void InitGlobalTidy();

	bool m_bTidySyn[SYN_XML + 1];

	/** AStyleѡ���� LGPLЭ�� */
	std::string m_TidyCpp;
	std::string m_TidyJava;
	std::string m_TidyCSharp;
	std::string m_TidyObjectiveC;

	/** Tidyѡ���� MITЭ�� */
	std::string m_TidyHtml;

	/** XMLѡ���� */
	std::string m_TidyXml;

	/** phpformatterѡ���� GPL2Э�� */
	std::string m_TidyPhp;

	/** JSMinѡ���� GPL */
	std::string m_TidyJs;

	/** CssTidyѡ���� */
	std::string m_TidyCss;

	/** JsonCppѡ���� */
	std::string m_TidyJson;

	/** SqlFormatterѡ���� */
	std::string m_TidySql;

	/** Ĭ�ϵ����Խṹ������ */
	static TidyDeafult m_TidyNames[MAX_SYN_LANG];
};

extern GlobalTidy g_GlobalTidy;
