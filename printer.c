#include "main.h"

/**
 * print_from_to - prints a range of char addresse.
 * @start: starting pointer.
 * @stop: stopping pointer.
 * @except: except pointer.
 *
 * Return: number bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

