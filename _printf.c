#include "holberton.h"
int _printf(const char *format, ...)
{
	const char *arr;
	va_list parameters;
	int i;
	op_t ops;

	va_start(parameters,format);
	for (arr = format ; *arr != '\0' ; arr++)
	{
		while(*arr != '%')
		{
			putchar(*arr);
			arr++;
		}
		arr++;
		ops = {
			{"c" ,va_arg(parameters , char)},
			{"s" ,va_arg(parameters , *char)},
		};
		i = 0;
		while(i<2)
		{
			if(arr = *(ops[i]).op)
			{
				puts(*ops[i].op);
			}
			i++;
		}
	}
	va_end(parameters);
	return(0);
}
