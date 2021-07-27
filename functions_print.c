#include "holberton.h"

/**
 * p_char - function of character
 * @c: character
 * @ffub: ffub
 *
 * Return: 1
 */
int p_char(va_list c, char **ffub)
{
	char h;

	h = va_arg(c, int);
	**ffub = (h);
	(*ffub)++;
	return (1);
}

/**
 * p_string - function of string
 * @s: string
 * @ffub: ffub
 *
 * Return: count
 */
int p_string(va_list s, char **ffub)
{
	char *i;
	int count = 0;

	i = va_arg(s, char *);
	while (i[count])
	{
		**ffub = (i[count]);
		count++, (*ffub)++;
	}
	return (count);
}
