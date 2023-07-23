#include "main.h"

/**
 * print_character - function that prints character.
 * @ap: argument pointer.
 *
 * Return: character to be printed.
 */
int print_character(va_list ap)
{
	unsigned int charCount = 0, ch = va_arg(ap, int);

	charCount += _putchar(ch);

	return (charCount);
}

/**
 * print_string - function that prints string.
 * @ap: argument pointer.
 *
 * Return: string of character to be printed.
 */
int print_string(va_list ap)
{
	char *str = va_arg(ap, char *);
	unsigned int charCount = 0;

	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	charCount += _puts(str);

	return (charCount);
}

/**
 * print_percent - function that prints % character.
 * @ap: argument pointer.
 *
 * Return: % character.
 */
int print_percent(va_list ap)
{
	(void)ap;
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

