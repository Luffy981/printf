#ifndef _PRINTF_
#define _PRINTF_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

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
int p_int(va_list i, char **ffub);
int p_octal(va_list o, char **ffub);
int number_to_buff(long  int number, char **ffub);
int p_binary(va_list b, char **ffub);
int p_unsigned(va_list u, char **ffub);
int p_reverse_string(va_list r, char **ffub);
int p_percent(va_list p, char **ffub);
int string_to_buff(char **bin, char **ffub, int size_string);
#endif
