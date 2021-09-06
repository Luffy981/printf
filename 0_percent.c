#include "main.h"
/**
 * p_percent - function to print '%'
 * @p: Unused paramater
 * @ffub: Double pointer to buffer
 *
 * Return: 1
 */
int p_percent(__attribute__((unused))va_list p, char **ffub)
{
	char r;
	int count = 0;

	r = '%';
	**ffub = r;
	(*ffub)++;
	count++;
	return (count);
}
/**
 * p_address - function to print the address
 * @p: Parameter
 * @ffub: Double pointer to buffer
 *
 * Return: 1
 */
int p_address(va_list p, char **ffub)
{
	long long int number;
	char str[] = "(nil)";
	char *rts = str;
	int count = 0;

	number = va_arg(p, long int);

	if (number == 0)
	{
		while (*rts != '\0')
		{
			**ffub = *rts;
			(*ffub)++;
			count++;
			rts++;
		}
		return (count);
	}
	**ffub = '0';
	(*ffub)++;
	count++;
	**ffub = 'x';
	(*ffub)++;
	count++;
	if (number < 0)
	{
		number = ULONG_MAX - number + 1;
	}
	count += number_to_hex(number, ffub);
	return (count);
}
/**
 * p_rot_string - function to print a string with rot format
 * @R: Parameter
 * @ffub: Double pointer to buffer
 *
 * Return: Return value count
 */
int p_rot_string(va_list R, char **ffub)
{
	char *str;
	int count = 0;
	char in[56] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[56] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *tuo = NULL;
	char string[] = "(ahyy)";
	char *rts = string;
	int a = 0;

	str = va_arg(R, char*);
	if (str == NULL)
	{
		while (*rts != 0)
		{
			**ffub = *rts;
			(*ffub)++;
			count++;
			rts++;
		}
	}
	while (*str != '\0')
	{
		for (; *str ; str++)
		{
			tuo = out;
			for (a = 0 ; in[a] != '\0' ; a++, tuo++)
			{
				if (*str == in[a])
				{
					**ffub = *tuo;
					(*ffub)++;
					count++;
					break;
				}
			}
			if (*tuo == '\0')
				**ffub = *str, (*ffub)++, count++;
		}
	}
	return (count);
}
