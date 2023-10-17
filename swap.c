#include "main.h"

/**
 * print_from_to - print range
 * @start: starting
 * @end: ending
 * @exp: except
 * Return: Succuess
*/

int print_from_to(char *start, char *end, char *exp)
{
	int sum = 0;

	while (start <= end)
	{
		if (start != exp)
			sum += _putcahr(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - reversing string
 * @ap: string
 * @pr: parameters
 * Return: Succuess
*/

int print_rev(va_list ap, pr_t *pr)
{
	int length, summation = 0;
	char *string = va_arg(ap, char *);
	(void)pr;

	if (string)
	{
		for (length = 0; *string; string++)
			length++;
		string--;
		for (; length > 0; length--, string--)
			summation += _putchar(*string);
	}
	return (summation);
}

/**
 * print_rot13 - rotating string
 * @ap: string
 * @pr: Prametars
 * Return: Success
*/


int print_rot13(va_list ap, pr_t *pr)
{
	int r = 0, ind = 0, c = 0;
	char array[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)pr;

	while (a[r])
	{
		if ((a[r] >= 'A' && a[r] <= 'Z')
				|| (a[r] >= 'a' && a[r] <= 'z'))
		{
			ind = a[r] - 65;
			c += _putchar(array[ind]);
		}
		else
			c += _putchar(a[r]);
		r++;
	}
	return (c);
}
