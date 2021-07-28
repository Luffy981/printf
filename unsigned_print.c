#include "holberton.h"

/**
 * p_binary - function to binary
 * @b: binary
 * @ffub: ffub
 *
 * Return: count
 */
int p_binary(va_list b, char **ffub)
{
	int n;
	long int num;
	char binary[50];
	char *bin = binary;
	int count = 0;

	n = va_arg(b, int);
	if (n < 0)
	{
		num = -n;
		num = 4294967295 - num + 1;
	} else
	{
		num = n;
	}
	while (num > 0)
	{
		*bin = (num % 2);
		num = num / 2;
		if (num == 0)
			break;
		bin++;
	}
	count += string_to_buff(&bin, ffub, bin - (char *)binary);
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
		**ffub = **bin + '0';
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