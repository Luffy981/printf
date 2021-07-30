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
