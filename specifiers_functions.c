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

