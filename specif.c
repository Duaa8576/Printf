#include "main.h"

/**
 * get_specifier - to format function
 * @s: string format
 * Return: success
 */
int (*get_specifier(char *s))(va_list ap, pr_t *pr)
{
	SP sp_t[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (sp_t[i].SP)
	{
		if (*s == sp_t[i].SP[0])
		{
			return (sp_t[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func  - to find format function
 * @s: string
 * @pr: parameter
 * @ap: pointer
 * Return: success
 */

int get_print_func(char *s, va_list ap, pr_t *pr)
{
	int (*f)(va_list, pr_t *) = get_specifier(s);

	if (f)
		return (f(ap, pr));
	return (0);
}

/**
 * get_flag  - to find flag  function
 * @s: string
 * @pr: parameter
 * Return: success
 */

int get_flag(char *s, pr_t *pr)
{
	int i = 0;

	switch (*s)
	{
		case '0':
			i = pr->zero = 1;
			break;
		case '+':
			i = pr->plus = 1;
			break;
		case '-':
			i = pr->minus = 1;
			break;
		case ' ':
			i = pr->space = 1;
			break;
		case '#':
			i = pr->hash = 1;
			break;
	}
	return (i);
}


/**
 * get_modifier - to find modifier function
 * @s: string
 * @pr: parameter
 * Return: success
 */

int get_modifier(char *s, pr_t *pr)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = pr->h = 1;
			break;
		case 'l':
			i = pr->l = 1;
			break;
	}
	return (i);
}

/**
 * get_width - to find width
 * @s: string
 * @pr: parameter
 * @ap: pointer
 * Return: success
 */

char *get_width(char *s, pr_t *pr, va_list ap)
{
	int w = 0;

	if (*s == '*')
	{
		w = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			w = w * 10 + (*s++ - '0');
	}
	pr->width = w;
	return (s);
}
