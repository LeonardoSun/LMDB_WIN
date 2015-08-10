#include "getopt.h"
#include <windows.h>

int getopt(int argc, TCHAR *argv[], TCHAR *opstring)
{
	static TCHAR *pIndexPosition = NULL;
	TCHAR *pArgString = NULL;
	TCHAR *pOptString;

	if (pIndexPosition != NULL) {

		if (*(++pIndexPosition)) {

			pArgString = pIndexPosition;
		}
	}
	if (pArgString == NULL) {

		if (optind >= argc) {

			pIndexPosition = NULL;
			return -1;
		}

		pArgString = argv[optind++];
		if ((_T('/') != *pArgString) &&
			(_T('-') != *pArgString)) {
			--optind;
			optarg = NULL;
			pIndexPosition = NULL;
			return -1;
		}

		if ((_tcscmp(pArgString, _T("-")) == 0) ||
			(_tcscmp(pArgString, _T("--")) == 0)) {
			optarg = NULL;
			pIndexPosition = NULL;
			return -1;
		}
		pArgString++;
	}
	if (_T(':') == *pArgString) {

		return (opterr ? (int)_T('?') : (int)_T(':'));
	}
	else if ((pOptString = _tcschr(opstring, *pArgString)) == 0) {

		optarg = NULL;
		pIndexPosition = NULL;
		return (opterr ? (int)_T('?') : (int)*pArgString);
	}
	else {

		if (_T(':') == _next_char(pOptString)) {

			if (_T('\0') != _next_char(pArgString)) {
				optarg = &pArgString[1];
			}
			else {

				if (optind < argc)
					optarg = argv[optind++];
				else {
					optarg = NULL;
					return (opterr ? (int)_T('?') : (int)*pArgString);
				}
			}
			pIndexPosition = NULL;
		}
		else {

			optarg = NULL;
			pIndexPosition = pArgString;
		}
		return (int)*pArgString;
	}
}

///// ²âÊÔDemo
//int _tmain(int argc, _TCHAR* argv[])
//{
//	// TCHAR c = _T('0');
//	int c = -1;
//	while (-1 != (c = ks_unility::getopt(argc, argv, _T("a:b:c:xy"))))
//	{
//		switch (c)
//		{
//		case _T('a'):
//			_tprintf(_T("-a %s\r\n"), ks_unility::optarg);
//			break;
//		case _T('b'):
//			_tprintf(_T("-b %s\r\n"), ks_unility::optarg);
//			break;
//		case _T('c'):
//			_tprintf(_T("-c %s\r\n"), ks_unility::optarg);
//			break;
//		case _T('x'):
//			_tprintf(_T("-x\r\n"));
//			break;
//		default:
//			_tprintf(_T("default.\r\n"));
//			break;
//		}
//	}
//	return 0;
//}  