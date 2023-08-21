#include "main.h"

/**
 * _printf - Custom implementation of printf function.
 * @format: The format string containing format specifiers.
 * @...: Additional arguments based on format specifiers.
 *
 * Return: Number of characters printed.
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
process_format(format, args, &count);
}
else
{
write(1, format, 1);
count++;
}
format++;
}

va_end(args);
return (count);
}
