#include "main.h"

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
 * handle_integer - Handles the 'd' and 'i' format specifiers.
 * @arguments: The va_list containing the argument list.
 * @count: Pointer to the count of characters printed.
 */
void handle_integer(va_list arguments, int *count)
{
int num = va_arg(arguments, int);
char buffer[20];
int len = snprintf(buffer, sizeof(buffer), "%d", num);
write(1, buffer, len);
*count += len;
}

/**
 * handle_unsigned_integer - Handles the 'u' format specifier.
 * @arguments: The va_list containing the argument list.
 * @count: Pointer to the count of characters printed.
 */
void handle_unsigned_integer(va_list arguments, int *count)
{
unsigned int u_num = va_arg(arguments, unsigned int);
char u_buffer[20];
int u_len = snprintf(u_buffer, sizeof(u_buffer), "%u", u_num);
write(1, u_buffer, u_len);
*count += u_len;
}

/**
 * handle_format - Handles format specifiers.
 * @specifier: The format specifier character.
 * @args: The va_list containing the argument list.
 * @count: Pointer to the count of characters printed.
 */
void handle_format(char specifier, va_list args, int *count)
{
switch (specifier)
{
case 'c':
handle_char(args, count);
break;
case 's':
handle_string(args, count);
break;
case 'd':
case 'i':
handle_integer(args, count);
break;
case 'u':
handle_unsigned_integer(args, count);
break;
default:
break;
}
}

