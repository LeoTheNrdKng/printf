#include "main.h"

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to write.
 *
 * Return: On success, 1 is returned. On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - Custom implementation of the printf function.
 * @format: The format string.
 * @...: Additional arguments depending on the format string.
 *
 * Return: The total number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;
	char *str;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				c = va_arg(args, int);
				count += _putchar(c);
				break;
			case 's':
				str = va_arg(args, char *);
				while (*str)
					count += _putchar(*str++);
				break;
			case '%':
				count += _putchar('%');
				break;
			default:
				break;
			}
		}
		else
			count += _putchar(*format);
		format++;
	}
	va_end(args);

	return (count);
}
