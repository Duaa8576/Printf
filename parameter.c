#include "main.h"
/**
 * init_params -  resets buffer and clear field
 * @pr: parameter
 * @ap: pointer
 * return: success
 */

void init_params(pr_t *pr, va_list ap)
{
	pr->uni = 0;
	pr->zero = 0;
	pr->plus = 0;
	pr->minus = 0;
	pr->space = 0;
	pr->hash = 0;

	pr->h = 0;
	pr->l = 0;

	pr->width = 0;
	pr->precision = UINT_MAX;
	(void)ap;
}
