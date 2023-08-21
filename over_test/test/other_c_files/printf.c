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
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
handle_char(args, &count);
break;
case 's':
handle_string(args, &count);
break;
case '%':
handle_percent(&count);
break;
case 'd':
case 'i':
handle_integer(args, &count);
break;
case 'u':
handle_unsigned_integer(args, &count);
break;
default:
write(1, format - 1, 2);
count += 2;
break;
}
}
else
{
_putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}
