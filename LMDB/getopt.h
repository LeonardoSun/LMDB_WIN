#ifdef _WIN32
#ifndef __GETOPT_H__
#define __GETOPT_H__
#include <tchar.h>


extern TCHAR* optarg;
extern int    optind;
extern int    opterr;

#define _next_char(X) (TCHAR)(*(X+1))
int getopt(int argc, TCHAR *argv[], TCHAR *opstring);
#endif // !__GETOPT_H__

#endif // _WIN32
