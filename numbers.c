#include "main.h"

/**
 * convert - Number converter function.
 * @num: number
 * @base: base
 * @flags: argument
 * @pr: struct
 * Return: success
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
	"0123456789abcdef" : "0123456789ABCDEF";
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

	if (pr->l)
		num = (unsigned long)va_arg(ap, unsigned long);
	else if (pr->h)
		num = (unsigned short int)va_arg(ap, unsigned int);
	else
		num = (unsigned int)va_arg(ap, unsigned int);
	pr->uni = 1;
	return (print_number(convert(num, 10, CONVERT_UNSIGNED, pr), pr));
}

/**
 * print_address - unsigned integer.
 * @ap: pointer
 * @pr: struct
 * Return: Success
*/

int print_address(va_list ap, pr_t *pr)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, pr);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, pr));
}
