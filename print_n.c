#include "main.h"

/**
 * _isdigit - check digit char
 * @c: character
 * Return: success
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - to string length
 * @s: string
 * Return: success
 */

int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - to the number options
 * @str: base number
 * @pr: parameter
 * Return: Success
 */

int print_number(char *str, pr_t *pr)
{
	unsigned int i = _strlen(str);
	int ng = (!pr->uni && *str == '-');

	if (!pr->precision && *str == '0' && !str[1])
		str = "";
	if (ng)
	{
		str++;
		i--;
	}
	if (pr->precision != UINT_MAX)
		while (i++ < pr->precision)
			*--str = '0';
	if (ng)
		*--str = '-';
	if (!pr->minus)
		return (print_number_right_shift(str, pr));
	else
		return (print_number_left_shift(str, pr));
}

/**
 * print_number_right_shift - to number options
 * @str base number
 * @pr: prameter
 * Return: success
 */

int print_number_right_shift(char *str, pr_t *pr)
{
	unsigned int n = 0, ng, ng2, i = _strlen(str);
	char pad = ' ';

	if (pr->zero && !pr->minus)
		pad = '0';
	ng = ng2 = (!pr->uni && *str == '-');
	if (ng && i < pr->width && pad == '0' && !pr->minus)
		str++;
	else
		ng = 0;
	if ((pr->plus && !ng2) ||
		(!pr->plus && pr->space && !ng2))
		i++;
	if (ng && pad == '0')
		n += _putchar('-');
	if (pr->plus && !ng && pad == '0' && !pr->uni)
		n += _putchar ('+');
	else if (!pr->plus && pr->space && !ng2 &&
			!pr->uni && pr->zero)
		n += _putchar(' ');
	while (i++ < pr->width)
		n += _putchar (pad);
	if (ng && pad == ' ')
		n += _putchar('-');
	if (pr->plus && !ng2 && pad == ' ' && !pr->uni)
		n += _putchar ('+');
	else if (!pr->plus && pr->space && !ng2 &&
			!pr->uni && !pr->zero)
		n += _putchar(' ');
	while (i++ < pr->width)
		n += _putchar(pad);
	if (ng && pad == ' ')
		n += _putchar('-');
	if (pr->plus && !ng2 && pad == ' ' && !pr->uni)
		n += _putchar('+');
	else if (!pr->plus && pr->space && !ng2 &&
			!pr->uni && !pr->zero)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - to number options
 * @str base number
 * @pr: prameter
 * Return: success
 */

int print_number_left_shift(char *str, pr_t *pr)
{
	unsigned int n = 0, ng, ng2, i = _strlen(str);
	char pad = ' ';

	if (pr->zero && !pr->minus)
		pad = '0';
	ng = ng2 = (!pr->uni && *str == '-');
	if (ng && i < pr->width && pad == '0' && !pr->minus)
		str++;
	else
		ng = 0;
	if (pr->plus && !ng2 && !pr->uni)
		n += _putchar('+'), i++;
	else if (pr->space && !ng2 && !pr->uni)
		n += _puts(str);
	while (i++ < pr->width)
		n += _putchar(pad);
	return (n);
}
