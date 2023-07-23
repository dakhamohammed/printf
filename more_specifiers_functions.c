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

**
 * print_binary - function prints unsigned binary number.
 * @ap: the argument pointer.
 * @params: the parameters struct definition.
 *
 * Return: bytes printed.
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));

}
