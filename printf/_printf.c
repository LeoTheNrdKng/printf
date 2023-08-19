#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 * Return: On success 1. On error, -1 is returned and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_c - prints a character
 * @args: A list of variadic arguments
 * Return: Number of characters printed
 */
int print_c(va_list args)
{
	char c = va_arg(args, int);
	_putchar(c);
	return (1);
}

/**
 * print_s - prints a string
 * @args: A list of variadic arguments
 * Return: Number of characters printed
 */
int print_s(va_list args)
{
	char *str = va_arg(args, char *);
	int length = 0;

	if (str != NULL)
	{
		while (str[length])
		{
			_putchar(str[length]);
			length++;
		}
	}
	return (length);
}

/**
 * print_percent - prints a percent symbol
 * @args: A list of variadic arguments (unused)
 * Return: Number of characters printed
 */
int print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}

/**
 * _printf - prints a formatted string
 * @format: The format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	/* Declare the variable `printed_chars` before the loop. */
	int printed_chars = 0;

	int i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				printed_chars += print_c(args);
			else if (format[i] == 's')
				printed_chars += print_s(args);
			else if (format[i] == '%')
				printed_chars += print_percent(args);
			else
				{
					_putchar('%');
					_putchar(format[i]);
					printed_chars += 2;
				}
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
		i++;
	}

	va_end(args);
	return (printed_chars);
}
