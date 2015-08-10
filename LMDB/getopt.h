#pragma once
#ifdef WIN32
#include <tchar.h>


TCHAR* optarg = NULL;
int    optind = 1;
int    opterr = 1;

#define _next_char(X) (TCHAR)(*(X+1))
int getopt(int argc, TCHAR *argv[], TCHAR *opstring);
#endif // WIN32
