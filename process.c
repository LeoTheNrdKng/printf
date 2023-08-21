#include "main.h"

/**
 * process_format - Processes a single format specifier.
 * @format: Pointer to the format string.
 * @args: The va_list containing the argument list.
 * @count: Pointer to the count of characters printed.
 *
 * Return: The number of characters processed in the format specifier.
 */
int process_format(const char **format, va_list args, int *count)
{
int chars_processed = 0;

if (**format == '\0')
return (0);

if (**format == '%')
{
(*format)++;
chars_processed++;

switch (**format)
{
case 'c':
case 's':
case '%':
case 'd':
case 'i':
case 'u':
case 'o':
case 'x':
case 'X':
handle_format(**format, args, count);
chars_processed++;
break;
default:
_putchar('%');
_putchar(**format);
(*count) += 2;
chars_processed += 2;
break;
}
}
else
{
_putchar(**format);
(*count)++;
chars_processed++;
}

(*format)++;
return (chars_processed);
}
