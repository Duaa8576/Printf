#include "main.h"

/**
 * get_precision - precisin from string
 * @p: format string
 * @pr: parameter
 * @ap: pointer
 * Return: success
 */
char get_precision(char *p, pr_t *pr, va_list ap)
{
	int a = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		a = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			a = a * 10 + (*p++ - '0');
	}
	pr->precision = d;
	return (p);
}
