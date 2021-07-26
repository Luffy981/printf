#include "holberton.h"
int (*check_match(const char *format))(va_list)
{
	unsigned int i;
	op_t ops[]={
		{"s",p_string},
		{"c",p_char},
		{NULL,NULL}
	};
	i=0;
 	while( ops[i].op != NULL)
	{
		if(*format == *(ops[i].op))
		{
			break;
		}
		i++;
	}
	return(*(ops[i]).f);
}
int _printf(const char *format, ...)
{
	const char *arr=NULL;
	int count=0;
	va_list parameters;
	int (*q)(va_list)=NULL;

	if(format == NULL)
	{
		return(0);
	}

	va_start(parameters,format);
	for (arr = format ; *arr != '\0' ; arr++)
	{
		while(*arr != '%' && *arr != '\0')
		{
			d_puts(*arr);
			count++;
			arr++;
			if(*arr == '%' && *(arr+1) == '%')
			{
				d_puts('%');
				arr++;
				arr++;
				count++;
			}
		}
		arr++;
		q = check_match(arr);
		if( q!=NULL)
		{
			count += q(parameters);
			continue;
		}
		if(*(arr+1)=='\0')
		{
			return(-1);
		}
		d_puts(*arr);
	}
	va_end(parameters);
	return(count);
}
