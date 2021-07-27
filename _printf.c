#include "holberton.h"
int (*check_match(const char *format))(va_list ,char **buff)
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
	const char *arr = NULL;
	int count = 0;
	char buff[2000];
	char *ffub = buff;
	va_list parameters;
	int (*q)(va_list,char **buff) = NULL;

	if(format == NULL)
	{
		return(0);
	}
	va_start(parameters,format);
	for (arr = format ; *arr ; arr++)
	{
		while(*arr != '%' && *arr != '\0')
		{
			*ffub++ =*arr++;
			count++;
		}
		if(*arr == '%' && *(arr+1) == '%')
		{
			*ffub = ('%');
			arr++, ffub++, count++;
			continue;
		}
		if(*arr == '%')
		{
			arr++;
			q = check_match(arr);
			if( q!=NULL)
			{
				count += q(parameters,&ffub);
				continue;
			}
		}
		if(*arr == '\0')
		{
			--arr;
		}
	}
	d_puts(buff,ffub-(char*)buff);
	va_end(parameters);
	return(count);
}
