#ifndef _PRINTF_
#define _PRINTF_
typedef struct op
{
	char *op;
	void *f;
}op_t;
int _printf(const char *format, ...);
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#endif
