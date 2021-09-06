#include "main.h"

/**
 * p_binary - function to binary
 * @b: binary
 * @ffub: ffub
 *
 * Return: count
 */
int p_binary(va_list b, char **ffub)
{
	int n, clean = 0, count = 0, a = 0;
	long int num;
	char binary[50];
	char *bin = binary;

	while (clean <= 50)
		binary[clean] = '\0', clean++;
	n = va_arg(b, int);
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
	} else
		num = n;
	while (num > 0)
	{
		*bin = (num % 2);
		num = num / 2;
		count++;
		if (num <= 0)
			break;
		bin++;
	}
	while (a < count)
	{
		**ffub = *bin + '0';
		(*ffub)++;
		bin--;
		a++;
	}
	return (count);
}
/**
 * string_to_buff - Function to put the string inside the buffer
 * @bin: Double pointer to buffer binery
 * @ffub: Double pointer to buffer
 * @size_string: the size of the string
 *
 * Return: count
 */
int string_to_buff(char **bin, char **ffub, int size_string)
{
	int count = 0;

	while (size_string >= 0)
	{
		**ffub = **bin;
		(*bin)--;
		(*ffub)++;
		count++;
		size_string--;
	}
	return (count);
}

/**
 * p_octal - function to octal
 * @o: octal
 * @ffub: ffub
 *
 * Return: count
 */

int p_octal(va_list o, char **ffub)
{
	int n;
	long int num;
	long int octal = 0;
	long int i = 1;
	int count = 0;

	n = va_arg(o, int);
	if (n < 0)
	{
		num = -n;
		num = 4294967295 - num + 1;
	} else if (n >= 0)
	{
		num = n;
	}

	while (num > 0)
	{
		octal += ((num % 8) * i);
		num = num / 8;
		i = i * 10;
	}

	count += number_to_buff(octal, ffub);
	return (count);
}
/**
 * p_unsigned - function to print unsigned number
 * @u: character
 * @ffub: ffub
 *
 * Return: 1
 */
int p_unsigned(va_list u, char **ffub)
{
	int n;
	long int num;
	int count = 0;

	n = va_arg(u, int);
	if (n < 0)
	{
		num = -n;
		num = 4294967295 - num + 1;
	} else
	{
		num = n;
	}
	count += number_to_buff(num, ffub);
	return (count);
}
/**
 * p_reverse_string - function to reverse a string
 * @r: character
 * @ffub: ffub
 *
 * Return: 1
 */
int p_reverse_string(va_list r, char **ffub)
{
	char *str;
	char **pstr = &str;
	int count = 0;
	int i = 0;

	str = va_arg(r, char *);
	if (str == NULL)
		return (0);
	while (**pstr != '\0')
	{
		(*pstr)++;
		i++;
	}
	(*pstr)--;
	while (i >= 0)
	{
		**ffub = **pstr;
		i--;
		if (i < 0)
			break;
		(*pstr)--;
		(*ffub)++;
		count++;
	}
	return (count);
}
