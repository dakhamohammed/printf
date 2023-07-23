#include "main.h"

/**
 * print_STRING - function for custom format specifier
 * @ap: argument pointer
 * @params: the parameters struct definition.
 *
 * Return: pointer chars printed.
 */
int print_STRING(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int charCount = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			charCount += _putchar('\\');
			charCount += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				charCount += _putchar('0');
			charCount += _puts(hex);
		}
		else
		{
			charCount += _putchar(*str);
		}
	}
	return (charCount);
}

/**
 * print_address - prints address.
 * @ap: argument pointer.
 * @params: the parameters struct definition.
 *
 * Return: bytes printed.
 */
int print_address(va_list ap, params_t *params)
{
	unsigned long int address = va_arg(ap, unsigned long int);
	char *str;

	if (!address)
		return (_puts("(nil)"));

	str = convert(address, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}

