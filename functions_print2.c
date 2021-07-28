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
	unsigned int n;
	int binary = 0;
	int i = 1;
	int count = 0;

	n = va_arg(b, int);

	while (n != 0)
	{
		binary = binary + (n % 2) * i;
		n = n / 2;
		i = i * 10;
	}

	count += number_to_buff(binary, ffub);
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
	int octal = 0;
	int i = 1;
	int count = 0;

	n = va_arg(o, int);

	while (n != 0)
	{
		octal = octal + (n % 8) * i;
		n = n / 8;
		i = i * 10;
	}

	count += number_to_buff(octal, ffub);
	return (count);
}
