#include "main.h"
/**
 * binary_string_to_buff - function to add a binary string in buffer
 * @bin: Double pointer to binary string
 * @ffub: Double pointer to buffer
 * @size_string: Size of string
 *
 * Return: 1
 */
int binary_string_to_buff(char **bin, char **ffub, int size_string)
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
