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
int p_rot_string(va_list R, char **ffub)
{
	char *str;
	int count = 0;
	char string[] = "(null)";
	char *rts = string;

	str = va_arg(R, char*);
	if (str == NULL)
	{
		while (*rts != 0)
		{
			**ffub = *rts;
			(*ffub)++;
			count++;
			rts++;
		}
	}
	while (*string)
	{
		if ((*str >= 65 && *str <= 78) ||
		    (*str >= 97 && *str <= 110))
		{
			*str = (*str + 13);
		} else if ((*str >= 79 && *str <= 90) ||
			   (*str >= 111 && *str <= 122))
		{
			*str = (*str - 13);
		}
		**ffub = *str;
		(*ffub)++;
		str++;
		count++;
	}
	return (count);
}
