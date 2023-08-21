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
