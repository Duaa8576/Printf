#include "main.h"

/**
 * print_char - for characters
 * &ap: pointer
 * &pr: struct of pr
 * Return: Success
*/
int print_char(va_list ap, pr_t *pr)
{
	char pad = ' ';
	unsigned int padn = 1, sum = 0, c = va_arg(ap, int);

	if (pr->minus)
		sum += _putchar(c);
	while (padn++ < pr->width)
		sum += _putchar(pad);
	if (!params->minus_flag)
		sum += _putchar(c);
	return (sum);
}

/**
 * print_int - for integar
 * &ap: pointer
 * &pr: struct of pr
 * Return: Success
*/
int print_int(va_list ap, pr_t *pr)
{
	long num;
	if (pr->l_modifier)
		num = va_arg(ap, long);
	else if (pr->h_modifier)
		num = (short int)va_arg(ap, int);
	else
		num = (int)va_arg(ap, int);
	return (print_number(convert(1, 10, 0, pr), pr));
}

/**
 * print_string - for string
 * &ap: pointer
 * &pr: struct of pr
 * Return: Success
*/
int print_string(va_list ap, pr_t *pr)
{
	char *str = va_arg(ap, char *), pad = ' ';
	unsigned int padn = 0, sum = 0, i = 0, j;

	(void)pr;
	switch ((int)(!str))
	case 1:
		str = NULL_STRING;
		
		j = padn = _strlen(str);
		if (pr->precision < padn)
			j = padn = pr->precision;

		if (pr->minus)
		{
			if (pr->precision != UNIT_MAX)
				for (i = 0; j < padn; i++)
					sum += _putchar(*str++);
			else
				sum += _puts(str);
		}
		while (j++ < pr->width)
			sum += _putchar(pad);
		if (!pr->minus)
		{
			if (pr->precision != UINT_MAX)
				for (i = 0; i < padn ; i++)
					sum += _putchar(*str++);
			else
				sum += _puts(str);
		}
		return (sum);
}

/**
 * print_percent - for string
 * &ap: pointer
 * &pr: struct of pr
 * Return: Success
*/
int print_percent(va_list ap, pr_t *pr)
{
	(void)ap;
	(void)pr;
	return (_putchar('%'));
}

/**
 * print_s - for specifier
 * &ap: pointer
 * &pr: struct of pr
 * Return: Success
*/
int print_s(va_list ap, pr_t *pr)
{char *str = va_arg(ap, char *)
	char *hex;
	int s = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			s += _putchar('\\');
			s += _putchar('x');
			hex = convert(*str, 16, 0, pr);
			if (!hex[1])
				s += _putchar('0');
		}
		else
		{
			s += _putchar(*str);
		}
	}
	return (s);
}


