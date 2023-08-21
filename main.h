#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to write.
 *
 * Return: On success, 1 is returned. On error, -1 is returned.
 */
int _putchar(char c);

/**
 * print_char - Prints a character.
 * @args: The va_list of arguments.
 * @count: The current character count.
 *
 * Return: The updated character count.
 */
int print_char(va_list args, int count);

/**
 * print_string - Prints a string.
 * @args: The va_list of arguments.
 * @count: The current character count.
 *
 * Return: The updated character count.
 */
int print_string(va_list args, int count);

/**
 * print_percent - Prints a percent character.
 * @args: The va_list of arguments.
 * @count: The current character count.
 *
 * Return: The updated character count.
 */
int print_percent(va_list args, int count);

/**
 * _printf - Custom implementation of the printf function.
 * @format: The format string.
 * @...: Additional arguments depending on the format string.
 *
 * Return: The total number of characters printed.
 */
int _printf(const char *format, ...);

#endif
