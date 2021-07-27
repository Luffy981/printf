#include "holberton.h"
int d_puts(char *buff , int size_buff)
{
	return(write(1 , buff , size_buff));
}
