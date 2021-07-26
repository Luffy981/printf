#include "holberton.h"
int p_char(va_list c)
{
	char h;
	h = va_arg(c,int);
	d_puts(h);
	return(1);
}
int p_string(va_list s)
{
	char *i;
	int count = 0;
	i = va_arg(s, char *);
	while(i[count])
	{
		d_puts(i[count]);
		count++;
	}
	return(count);
}
