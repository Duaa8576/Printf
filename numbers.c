#include "main.h"

/**
 * convert - converter function.
 * @num: number
 * @base: base
 * @flags: argument
 * @pr: struct
 *
*/
char *convert(long int num, int base, int flags, pr_t *pr)
{
	static char *arr, buff[50];
	char sign = 0, *ptr;
	unsigned long n = num;
	(void)pr;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	arr = flags & CONVERT_LOWERCASE ? 
		"0123456789abcdef" : "0123456789ABCDEF" ;
	ptr = &buff[49];
	*ptr = '\0';

	do	{
		*--ptr = arr[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}


/**
 * print_unsigned - unsigned integer.
 * @ap: pointer
 * @pr: struct
 * Return: Success
*/

int print_unsigned(va_list ap, pr_t *pr)
{
	unsigned long num;

	if (pr->l_modifier)
		num = (unsigned long)va_arg(ap, unsigned long);
	else if (pr->h_modifier)
		num = (unsigned short int)va_arg(ap, unsigned int);
	else
		num = (unsigned int)va_arg(ap, unsigned int);
	pr->unsign = 1;
	return (print_number(convert(num, 10, CONVERT_UNSIGNED, pr), pr));
}

/**
 * print_unsigned - unsigned integer.
 * @ap: pointer
 * @pr: struct
 * Return: Success
*/

int print_address(va_list ap, pr_t *pr)
{
	unsigned long int n + va_arg(ap, unsigned long int);
	char *num;

	if (!n)
		return (_puts("(nil)"));

	num = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, pr);
	*--num = 'x';
	*--num = '0';
	return (print_number(num, pr));
}
