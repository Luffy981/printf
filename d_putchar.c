#include "holberton.h"
int d_puts(char c)
{
	return(write(1 , &c , 1));
}
