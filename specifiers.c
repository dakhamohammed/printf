#include "main.h"

/**
 * get_specifier - function tht finds the format function
 * @s: string of the format.
 *
 * Return: the number of bytes printed.
 */
int (*get_specifier(char *s))(va_list ap)
{
	specifier_t specifiers[] = {
		{"c", print_character},
		{"s", print_string},
		{"%", print_percent},
		{NULL, NULL}
	};

	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - function finds the format function.
 * @s: string of the format.
 * @ap: argument pointer.
 *
 * Return: pointer function to argumet pointer.
 */
int get_print_func(char *s, va_list ap)
{
	int (*f)(va_list) = get_specifier(s);

	if (f)
		return (f(ap));
	return (0);
}

