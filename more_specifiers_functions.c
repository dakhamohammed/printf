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

