#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#define LOCAL_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct PR - struct parameters
 * @uni: unsign value
 * @plus: plus flag specified
 * @minus: minus flag specified
 * @space: space flag specified
 * @hash: hash flag specified
 * @zero: zero value
 *
 * @h: short moifier specefied
 * @l: long modifier specefied
 *
 * @width: width specefied
 * @preci: precision specefied
 *
 */

typedef struct PR
{
	unsigned int uni	: 1;
	unsigned int zero	: 1;
	unsigned int plus	: 1;
	unsigned int minus	: 1;
	unsigned int space	: 1;
	unsigned int hash	: 1;

	unsigned int h  : 1;
	unsigned int l  : 1;

	unsigned int width;
	unsigned int precision;
} pr_t;

/**
 * struct SP - struct token
 * @SP: format token
 * @f: function
 */
typedef struct SP
{
	char *SP;
	int (*f)(va_list, pr_t *);
} sp_t;

/* _put.c function */
int _puts(char *str);
int _putchar(int c);

/* print functions */
int print_int(va_list ap, pr_t *pr);
int print_char(va_list ap, pr_t *pr);
int print_string(va_list ap, pr_t *pr);
int print_S(va_list ap, pr_t *pr);
int print_percent(va_list ap, pr_t *pr);

/* numbers functions */
int print_unsigned(va_list ap, pr_t *pr);
int print_address(va_list ap, pr_t *pr);
char *convert(long int num, int base, int flags, pr_t *pr);

/* specifier functions */
char *get_width(char *s, pr_t *pr, va_list ap);
int get_flag(char *s, pr_t *pr);
int get_modifier(char *s, pr_t *pr);
int get_print_func(char *s, va_list ap, pr_t *pr);
int (*get_specifier(char *s))(va_list ap, pr_t *pr);

/* convert number functions */
int print_binary(va_list ap, pr_t *pr);
int print_octal(va_list ap, pr_t *pr);
int print_hex(va_list ap, pr_t *pr);
int print_HEX(va_list ap, pr_t *pr);

/* reverse and swap functions */
int print_from_to(char *start, char *end, char *exp);
int print_rev(va_list ap, pr_t *pr);
int print_rot13(va_list ap, pr_t *pr);

/* print number functions */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, pr_t *pr);
int print_number_right_shift(char *str, pr_t *pr);
int print_number_left_shift(char *str, pr_t *pr);

/* other funcation */
void init_params(pr_t *pr, va_list ap);
char get_precision(char *p, pr_t *pr, va_list ap);
int _printf(const char *format, ...);
#endif
