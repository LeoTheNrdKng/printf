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
 * handle_char - Handles the 'c' format specifier.
 * @arguments: The va_list containing the argument list.
 * @count: Pointer to the count of characters printed.
 */
void handle_char(va_list arguments, int *count)
{
char ch = (char)va_arg(arguments, int);
*count += _putchar(ch);
}

/**
 * handle_string - Handles the 's' format specifier.
 * @arguments: The va_list containing the argument list.
 * @count: Pointer to the count of characters printed.
 */
void handle_string(va_list arguments, int *count)
{
char *str = va_arg(arguments, char *);
while (*str)
{
*count += _putchar(*str);
str++;
}
}

/**
 * handle_percent - Handles the '%%' format specifier.
 * @count: Pointer to the count of characters printed.
 */
void handle_percent(int *count)
{
*count += _putchar('%');
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
int num;
unsigned int u_num;
char buffer[20];
char u_buffer[20];

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
num = va_arg(args, int);
{
int len = snprintf(buffer, sizeof(buffer), "%d", num);
write(1, buffer, len);
count += len;
}
break;
case 'u':
u_num = va_arg(args, unsigned int);
{
int u_len = snprintf(u_buffer, sizeof(u_buffer), "%u", u_num);
write(1, u_buffer, u_len);
count += u_len;
}
break;
default:
write(1, format - 1, 2);
count += 2;
}
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
