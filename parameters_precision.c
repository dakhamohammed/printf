#include "main.h"

/**
 * init_params - clears struct fields and reset buffer.
 * @params: the parameters struct definition.
 * @ap: the argument pointer.
 *
 * Return: void, no return.
 */
void init_params(params_t *params, va_list ap)
{
	params->unsign = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;

	params->width = 0;

	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)ap;
}

/**
 * get_precision - gets the precision from the format string
 * @s: the format string.
 * @params: the parameters struct definition.
 * @ap: the argument pointer.
 *
 * Return: pointer to precision character.
*/
char *get_precision(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->precision = d;
	return (s);
}

