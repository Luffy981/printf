#include "holberton.h"
/**
 * p_percent - function to print '%'
 * @p: Unused paramater
 * @ffub: Double pointer to buffer
 *
 * Return: 1
 */
int p_percent(__attribute__((unused))va_list p, char **ffub)
{
	char r;
	int count = 0;

	r = '%';
	**ffub = r;
	(*ffub)++;
	count++;
	return (count);
}
/**
 * p_address - function to print the address
 * @p: Parameter
 * @ffub: Double pointer to buffer
 *
 * Return: 1
 */
int p_address(va_list p, char **ffub)
{
	long int number;
	char str[] = "(null)";
	char *rts = str;
	int count = 0;

	number = va_arg(p, long int);
	if (number == 0)
	{
		while (*rts != '\0')
		{
			**ffub = *rts;
			(*ffub)++;
			count++;
			rts++;
		}
	}
	**ffub = '0';
	(*ffub)++;
	count++;
	**ffub = 'x';
	(*ffub)++;
	count++;
	count += number_to_hex(number, ffub);
	return (count);
}
