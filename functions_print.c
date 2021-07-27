#include "holberton.h"

/**
 * p_char - function of character
 * @c: character
 * @ffub: ffub
 *
 * Return: 1
 */
int p_char(va_list c, char **ffub)
{
	char h;

	h = va_arg(c, int);
	**ffub = (h);
	(*ffub)++;
	return (1);
}

/**
 * p_string - function of string
 * @s: string
 * @ffub: ffub
 *
 * Return: count
 */
int p_string(va_list s, char **ffub)
{
	char *i;
	int count = 0;

	i = va_arg(s, char *);
	if (i == NULL)
		i = "(null)";
	while (i[count])
	{
		**ffub = (i[count]);
		count++, (*ffub)++;
	}
	return (count);
}

/**
 * p_integer - function of integer
 * @d: integer
 * @ffub: ffub
 *
 * Return: count
 */
int number_to_buff(int number,char **ffub)
{
	unsigned int num;
	unsigned int r;
	int i;/*iterador para obtener f*/
	int b; /*Contador de dígitos*/
	int f; /*potencia de 10*/
	int t;/*Extrae digito por digito y lo agrega al buffer*/
	int count = 0;/*Contador de digitos almacenados en el buffer*/
	b = 1;
	f = 1;
	if (number < 0)
	{
		**ffub = '-';
		num = -number;
		count++, (*ffub)++;
	} else
	{
		num = number;
	}
	r = num;
	while (num / 10 >= 1)/*contador de digitos = b*/
	{
		num = num / 10;
		b++;
	}
	for (i = 1 ; i < b ; i++)/*potencia de 10*/
	{
		f *= 10;
	}
	while (b >= 1)/*asigna digito por digito al buffer*/
	{
		t = (r / f) % 10;
		f = f / 10;
		**ffub = t + '0';
		count++, (*ffub)++;
		b--;
	}
	return(count);
}
int p_integer(va_list d, char **ffub)
{
	int n;/*Numero extraido de los argumentos*/
	int count = 0;/*Contador de digitos almacenados	en el buffer*/

	n = va_arg(d, int);
	count += number_to_buff(n,ffub);

	return (count);
}
int p_int(va_list i, char **ffub)
{
	int n;/*Numero extraido de los argumentos*/
	int count = 0;/*Contador de digitos almacenados en el buffer*/
	n = va_arg(i, int);
	count += number_to_buff(n,ffub);
	return (count);
}
