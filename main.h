#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 *
 * Return: On success, 1. On error, -1 is returned and errno is set appropriately.
 */
int _putchar(char c);

/**
 * handle_char - Handles the formatting and printing of a character
 * @arguments: The list of arguments containing the character to print
 * @count: A pointer to the counter tracking the number of characters printed
 */
void handle_char(va_list arguments, int *count);

/**
 * handle_string - Handles the formatting and printing of a string
 * @arguments: The list of arguments containing the string to print
 * @count: A pointer to the counter tracking the number of characters printed
 */
void handle_string(va_list arguments, int *count);

/**
 * handle_percent - Handles the formatting and printing of a percent symbol
 * @count: A pointer to the counter tracking the number of characters printed
 */
void handle_percent(int *count);

/**
 * process_format - Processes the format string and its arguments
 * @format: The format string containing the format specifiers
 * @args: The list of arguments to be formatted and printed
 * @count: A pointer to the counter tracking the number of characters printed
 */
void process_format(const char *format, va_list args, int *count);

/**
 * _printf - Custom printf function with variable arguments
 * @format: The format string containing the format specifiers
 * @...: Additional arguments to be formatted and printed
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...);

/**
 * print_binary - Prints an unsigned integer in binary format.
 * @num: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_binary(unsigned int num);

#endif /* MAIN_H */
