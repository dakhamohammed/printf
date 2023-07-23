#include "main.h"

/**
 * print_character - function that prints character.
 * @ap: argument pointer.
 * @params: the parameters struct definition.
 *
 * Return: character to be printed.
 */
int print_character(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, charCount = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		charCount += _putchar(ch);
	while (pad++ < params->width)
		charCount += _putchar(pad_char);
	if (!params->minus_flag)
		charCount += _putchar(ch);
	return (charCount);
}

/**
 * print_string - function that prints string.
 * @ap: argument pointer.
 * @params: the parameters struct definition.
 *
 * Return: string of character to be printed.
 */
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, charCount = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				charCount += _putchar(*str++);
		else
			charCount += _puts(str);
	}
	while (j++ < params->width)
		charCount += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				charCount += _putchar(*str++);
		else
			charCount += _puts(str);
	}
	return (charCount);
}

/**
 * print_percent - function that prints % character.
 * @ap: argument pointer.
 * @params: the parameters struct definition.
 *
 * Return: % character.
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_int - function that prints integer
 * @ap: argument pointer
 * @params: the parameters struct definition.
 *
 * Return: number chars printed.
 */
int print_int(va_list ap, params_t *params)
{
	long integer;

	if (params->l_modifier)
		integer = va_arg(ap, long);
	else if (params->h_modifier)
		integer = (short int)va_arg(ap, int);
	else
		integer = (int)va_arg(ap, int);
	return (print_number(convert(integer, 10, 0, params), params));
}

/**
 * print_unsigned - function that prints unsigned integer numbers
 * @ap: argument pointer.
 * @params: the parameters struct definition.
 *
 * Return: bytes printed.
 */
int print_unsigned(va_list ap, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}

