#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define NULL_STRING "(null)"

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list);
} specifier_t;

/* _prinf.c */
int _printf(const char *format, ...);

/* _putchar.c */
int _puts(char *str);
int _putchar(int c);

/* specifiers.c */
int (*get_specifier(char *s))(va_list ap);
int get_print_func(char *s, va_list ap);

/* printer.c */
int print_from_to(char *start, char *stop, char *except);


/* specifiers_functions.c */
int print_character(va_list ap);
int print_string(va_list ap);
int print_percent(va_list ap);

#endif /* end of _MAIN_H_*/

