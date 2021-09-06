#include "main.h"
/**
 * p_heX_string - function to print a string with hexadecimal characaters
 * @S: Argument
 * @ffub: Double pointer to buffer
 *
 * Return: Return count
 */
int p_heX_string(va_list S, char **ffub)
{
	char *str;
	int count = 0;
	char **rts = &str;
	char r[] = "\\x";
	char *p = r;

	str = va_arg(S, char*);
	if (str == NULL)
		str = "(null)";
	while (**rts != '\0')
	{
		if ((**rts > 0 && **rts < 32) || **rts >= 127)
		{
			**ffub = *p;
			(*ffub)++;
			count++;
			p++;
			**ffub = *p;
			(*ffub)++;
			p--;
			count++;
			count += number_to_heX(**rts, ffub);
			(*rts)++;
		}
		**ffub = **rts;
		(*ffub)++;
		(*rts)++;
		count++;
	}
	return (count);
}
/**
 * number_to_heX - function to convert number to heXadecimal
 * @n: Argument
 * @ffub: Double pointer to buff
 *
 * Return: Return count
 */
int number_to_heX(long int n, char **ffub)
{
	char hex[] = "0123456789ABCDEF";
	char Xeh[50];
	int a = 0;
	long int t;
	char *x = Xeh;
	int count = 0;

	while (a <= 50)
		Xeh[a] = '\0', a++;
	while (n != 0)
	{
		t = n % 16;
		*x = hex[t];
		count++;
		n /= 16;
		x++;
	}
	x--;
	count--;
	return (string_to_buff(&x, ffub, count));
}
/**
 * p_heX_number - function to convert a number to hexadecimal
 * @X: Argument
 * @ffub: Double pointer to buffer
 *
 * Return: Return count
 */
int p_heX_number(va_list X, char **ffub)
{
	int n;
	long int num;
	int count = 0;

	n = va_arg(X, int);
	if (n == 0)
	{
		**ffub = n + '0';
		(*ffub)++;
		return (1);
	}
	if (n < 0)
	{
		num = -n;
		num = 4294967295 - num + 1;
	} else if (n >= 0)
	{
		num = n;
	}
	count += number_to_heX(num, ffub);
	return (count);
}
/**
 * p_hex_number - function to convert a number to hexadecimal
 * @x: Argument
 * @ffub: Double pointer to buffer
 *
 * Return: Return count
 */
int p_hex_number(va_list x, char **ffub)
{
	int n;
	long int num;
	int count = 0;

	n = va_arg(x, int);
	if (n == 0)
	{
		**ffub = n + '0';
		(*ffub)++;
		return (1);
	}
	if (n < 0)
	{
		num = -n;
		num = 4294967295 - num + 1;
	} else if (n >= 0)
	{
		num = n;
	}
	count += number_to_hex(num, ffub);
	return (count);
}
/**
 * number_to_hex - function to convert number to heXadecimal
 * @n: Argument
 * @ffub: Double pointer to buff
 *
 * Return: Return count
 */
int number_to_hex(long int n, char **ffub)
{
	char hex[] = "0123456789abcdef";
	char Xeh[50];
	int a = 0;
	long int t;
	char *x = Xeh;
	int count = 0;

	while (a <= 50)
		Xeh[a] = '\0', a++;
	while (n != 0)
	{
		t = n % 16;
		*x = hex[t];
		count++;
		n /= 16;
		x++;
	}
	x--;
	count--;
	return (string_to_buff(&x, ffub, count));
}
