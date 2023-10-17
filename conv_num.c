#include "main.h"

/**
 * print_hex - hex lower
 * @ap: pointer
 * @pr: struct
 * Return: Success
*/
int print_hex(va_list ap, pr_t *pr)
{
	unsigned long l;
	int n = 0;
	char *str;

	if (pr->l)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (pr->h)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, pr);
	if (pr->hash && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	pr->uni = 1;
	return (n += print_number(str, pr));

}

/**
 * print_HEX - hexadicimal upper
 * @ap: pointer
 * @pr: struct
 * Return: Success
*/

int print_HEX(va_list ap, pr_t *pr)
{
	unsigned long l;
	int n = 0;
	char *str;

	if (pr->l)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (pr->h)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, pr);
	if (pr->hash && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	pr->uni = 1;
	return (n += print_number(str, pr));
}

/**
 * print_binary - binary number
 * @ap: pointer
 * @pr: struct
 * Return: Success
*/

int print_binary(va_list ap, pr_t *pr)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, pr);
	int c = 0;

	if (pr->hash && n)
		*--str = '0';
	pr->uni = 1;
	return (c += print_number(str, pr));
}

/**
 * print_octal - octal number
 * @ap: pointer
 * @pr: struct
 * Return: Success
*/

int print_octal(va_list ap, pr_t *pr)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (pr->l)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (pr->h)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = convert(1, 8, CONVERT_UNSIGNED, pr);

	if (pa->hash && l)
		*--str = '0';
	pr->uni = 1;
	return (c += print_number(str, pr));
}
