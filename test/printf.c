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
 * print_char - Prints a character.
 * @args: The va_list of arguments.
 * @count: The current character count.
 *
 * Return: The updated character count.
 */
int print_char(va_list args, int count)
{
char c = va_arg(args, int);
count += _putchar(c);
return (count);
}

/**
 * print_string - Prints a string.
 * @args: The va_list of arguments.
 * @count: The current character count.
 *
 * Return: The updated character count.
 */
int print_string(va_list args, int count)
{
char *str = va_arg(args, char *);
while (*str)
count += _putchar(*str++);
return (count);
}

/**
 * print_percent - Prints a percent character.
 * @args: The va_list of arguments.
 * @count: The current character count.
 *
 * Return: The updated character count.
 */
int print_percent(va_list args, int count)
{
(void)args;
count += _putchar('%');
return (count);
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

va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
count = print_char(args, count);
break;
case 's':
count = print_string(args, count);
break;
case '%':
count = print_percent(args, count);
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
