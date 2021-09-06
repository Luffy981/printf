#include "main.h"

/**
 * d_puts - function for putchar
 * @buff: buff
 * @size_buff: size of buff
 *
 * Return: buff
 */
int d_puts(char *buff, int size_buff)
{
	return (write(1, buff, size_buff));
}
