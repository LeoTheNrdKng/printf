#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes a character to standard output.
 * @c: The character to be written.
 * Return: On success, the number of characters written.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * _printf - Produces output according to a format.
 * @format: Format string containing characters and specifiers.
 *
 * Description:
 * This function processes the format string and calls appropriate printing
 * functions based on the conversion specifiers. It also handles flags for
 * formatting options.
 *
 * Return:
 * The total number of characters printed.
 */
int _printf(const char *format, ...)
{
const char *p;
va_list arguments;

register int count = 0;

va_start(arguments, format);
if (!format || (format[0] == '%' && !format[1]))
{
va_end(arguments);
return (-1);
}
if (format[0] == '%' && format[1] == ' ' && !format[2])
{
va_end(arguments);
return (-1);
}
for (p = format; *p; p++)
{
if (*p == '%')
{
p++;
if (*p == 'c')
{
char ch = (char)va_arg(arguments, int);
count += _putchar(ch);
continue;
}
else if (*p == 's')
{
char *str = va_arg(arguments, char *);
while (*str)
{
count += _putchar(*str);
str++;
}
continue;
}
else if (*p == '%')
{
count += _putchar('%');
continue;
}
}
count += _putchar(*p);
}
va_end(arguments);
return (count);
}
