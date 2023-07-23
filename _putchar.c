#include "main.h"

/**
 * _puts - function that prints a string with newline.
 * @str: string of characters to print.
 *
 * Return: length of the string of characters.
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - function that writes the character c to stdout
 * @c: The character to print.
 *
 * Return: on success 1,
 * on error, -1 is returned, and error is set appropriately.
 */
int _putchar(int c)
{
	static int i;
	static char buf[LOCAL_BUFFER];

	if (c == -1 || i >= LOCAL_BUFFER)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != -1)
		buf[i++] = c;
	return (1);
}

