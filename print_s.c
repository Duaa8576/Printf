#include "main.h"

/**
 * _puts -to  print string
 * @str: string
 * Return: success
 */

int _puts(char *str)
{
	char *s = str;

	while (*str)
		_putchar(*str++);
	return (str - s);
}

/**
 * _putchar - to write caracter
 *  @c: caracter
 *  Return: success
 */

int _putchar(int c)
{
	static int i;
	static char b[LOCAL_BUF_SIZE];

	if (c == BUF_FLUSH || i >= LOCAL_BUF_SIZE)
	{
		write(1, b, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		b[i++] = c;
	return (1);
}
