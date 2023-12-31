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

/**
 * print_reverse - prints string in reverse.
 * @ap: string
 * @params: the parameters struct definition.
 *
 * Return: number bytes printed
 */
int print_reverse(va_list ap, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *);

	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - function prints string in rot13.
 * @ap: string arg.
 * @params: the parameters struct definition.
 *
 * Return: number bytes printed.
 */
int print_rot13(va_list ap, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}

