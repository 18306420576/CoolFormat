// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� COOLFORMATLIB_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// COOLFORMATLIB_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#include <string>

#ifdef COOLFORMATLIB_EXPORTS
#define COOLFORMATLIB_API __declspec(dllexport)
#else
#define COOLFORMATLIB_API __declspec(dllimport)
#endif

#ifdef __cplusplus    // If used by C++ code, 
extern "C" {          // we need to export the C interface
#endif

COOLFORMATLIB_API bool DoFormatter(unsigned int nLanguage,
	const char *pszTextIn,
	char *pszTextOut,
	int &nTextOut,
	char *pszMsgOut,
	int &nMsgOut,
	unsigned int uCodepage = 0,
	const char *pszEol = NULL,
	const char *pszInitIndent = NULL);

COOLFORMATLIB_API void ShowSettings();

#ifdef __cplusplus
}
#endif