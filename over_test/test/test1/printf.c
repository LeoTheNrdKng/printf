#include "main.h"

/**
 * _printf - Custom printf function that handles characters.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
int count = 0;
va_list arguments;
const char *ptr;

va_start(arguments, format);

for (ptr = format; *ptr != '\0'; ptr++)
{
if (*ptr == '%')
{
ptr++;
if (*ptr == 'c')
{
char ch = va_arg(arguments, int);
count += _putchar(ch);
}
else if (*ptr == 's')
{
char *str = va_arg(arguments, char *);
while (*str)
{
count += _putchar(*str);
str++;
}
}
else if (*ptr == '%')
{
count += _putchar('%');
}
}
else
{
count += _putchar(*ptr);
}
}

va_end(arguments);

return (count);
}
