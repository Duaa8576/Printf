#include "main.h"

/**
 * _printf - to print everythings
 * @format: string
 * Return: Success
 *
*/
int _printf(const char *format, ...)
{
	char *c, *start;
	int summation = 0;
	va_lsit ap;
	pr_t pr = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (c = (char *)format; *c; c++)
	{
		init_params(&pr, ap);
		if (*c != '%')
		{
			summation += _putchar(*p);
			continue;
		}
		start = c;
		c++;
		while (get_flag(c, &pr))
		{
			c++;
		}
		c = get_width(c, &pr, ap);
		c = get_precision(c, &pr, ap);
		if (get_modifier(c, &pr))
			c++;
		if (!get_specifier(c))
			summation += print_from_to(start, c, pr.l
				       || pr.h ? c - 1 : 0);
		else
			summation += get_print_func(c, ap, &pr);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (summation);
}


