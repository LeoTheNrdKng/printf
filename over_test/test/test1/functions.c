#include "main.h"

/**
 * _putchar - Writes a character to the standard output.
 * @c: The character to be written.
 *
 * Return: Upon success, 1. Otherwise, -1 is returned and errno is set.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * handle_char - Handles a character argument for printing.
 * @arguments: A va_list containing the list of arguments.
 * @count: A pointer to the count of characters printed.
 */
void handle_char(va_list arguments, int *count)
{
char ch = (char)va_arg(arguments, int);
*count += _putchar(ch);
}

/**
 * handle_string - Handles a string argument for printing.
 * @arguments: A va_list containing the list of arguments.
 * @count: A pointer to the count of characters printed.
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
 * handle_percent - Handles the '%' character for printing.
 * @count: A pointer to the count of characters printed.
 */
void handle_percent(int *count)
{
*count += _putchar('%');
}

/**
 * print_binary - Prints an unsigned integer in binary format.
 * @num: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_binary(unsigned int num)
{
char binary[32];
int i = 0;

if (num == 0)
{
return (_putchar('0'));
}

while (num > 0)
{
binary[i++] = (num & 1) + '0';
num >>= 1;
}

for (i--; i >= 0; i--)
{
_putchar(binary[i]);
}

return (i + 1);
}
