#include "holberton.h"
/**
 * check_match - match with the functions respectively
 * @format: string that contains the format
 *
 * Return: element of struct
 */
int (*check_match(const char *format))(va_list, char **buff)
{
	unsigned int i;
	op_t ops[] = {
		{"s", p_string},
		{"c", p_char},
		{"%", p_percent},
		{"d", p_integer},
		{"i", p_int},
		{"o", p_octal},
		{"b", p_binary},
		{"u", p_unsigned},
		{"r", p_reverse_string},
		{"X", p_heX_number},
		{"S", p_heX_string},
		{"x", p_hex_number},
		{"p", p_address},
		{NULL, NULL}
	};
	i = 0;
	while (ops[i].op != NULL)
	{
		if (*format == *(ops[i].op))
		{
			break;
		}
		i++;
	}
	return (*(ops[i]).f);
}
/**
 * _printf - prints formatted data to stdout
 * @format: string that contains the format to print
 *
 * Return: number of characters
 */
int _printf(const char *format, ...)
{
	const char *arr = NULL;
	int a = 0, count = 0;
	char buff[2050];
	char *ffub = buff;
	va_list parameters;
	int (*q)(va_list, char **buff) = NULL;

	while (a <= 2050)
		buff[a] = '\0', a++;
	if (format == NULL)
		return (0);
	va_start(parameters, format);
	for (arr = format ; *arr ; arr++)
	{
		while (*arr != '%' && *arr != '\0')
			*ffub = *arr, ffub++, arr++, count++;
		while (*arr == '%')
		{
			arr++;
			while (*arr == ' ')
				arr++;
			q = check_match(arr);
			if (q != NULL)
				count += q(parameters, &ffub), arr++;
			else
			{
				*ffub = '%', count++, ffub++;
				if (*arr == '\n')
				{
					*ffub = ' ', count++, ffub++;
				}
			}
		}
		if (*arr != '%')
			arr--;
	}
	d_puts(buff, ffub - (char *)buff + 1);
	va_end(parameters);
	return (count);
}
