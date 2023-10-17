#include "main.h"

/**
 * prit_hex - hex lower
 * @ap: pointer
 * @pr: struct
 * Return: Success
*/
int prit_hex(va_list ap, pr_t *pr)
{
	unsigned long l;
	int n = 0;
	char *str;

	if (pr->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (pr->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, pr);
	if (pr->hash && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	pr->unsign = 1;
	return (n += print_number(str, pr));

}
int prit_binary(va_list ap, pr_t *pr)
int prit_octal(va_list ap, pr_t *pr)
int prit_HEX(va_list ap, pr_t *pr)
