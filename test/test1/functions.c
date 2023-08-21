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
 *
 * Description: This function retrieves a character argument from va_list
 *              and prints it to the standard output. It also updates the
 *              character count.
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
 *
 * Description: This function retrieves a string argument from va_list
 *              and prints it to the standard output character by character.
 *              It also updates the character count.
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
 *
 * Description: This function prints the '%' character to the standard output
 *              and updates the character count.
 */
void handle_percent(int *count)
{
*count += _putchar('%');
}
