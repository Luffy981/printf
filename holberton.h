#ifndef _PRINTF_
#define _PRINTF_
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
typedef struct op
{
	char *op;
	int (*f)(va_list);
} op_t;
int _printf(const char *format, ...);
int d_puts(char c);
int p_char(va_list);
int (*check_match(const char *format))(va_list);
int p_string(va_list);
int _strlen(const char *str);
#endif
