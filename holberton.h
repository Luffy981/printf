#ifndef _PRINTF_
#define _PRINTF_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct op - structure containing
 * @op: the location and method to translate data to characters
 * @f: print function for specific type
 *
 * Return: op
 */

typedef struct op
{
	char *op;
	int (*f)(va_list, char **ffub);
} op_t;

int _printf(const char *format, ...);
int d_puts(char *buff, int size_buff);
int p_char(va_list, char **ffub);
int (*check_match(const char *format))(va_list, char **ffub);
int p_string(va_list, char **ffub);
int p_integer(va_list d, char **ffub);

#endif
