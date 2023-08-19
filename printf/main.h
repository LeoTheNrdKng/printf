#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 * Return: On success 1, and -1 is returned on error.
 */
int _putchar(char c);

/**
 * print_c - prints a character
 * @args: A list of variadic arguments
 * Return: Number of characters printed
 */
int print_c(va_list args);

/**
 * print_s - prints a string
 * @args: A list of variadic arguments
 * Return: Number of characters printed
 */
int print_s(va_list args);

/**
 * print_percent - prints a percent symbol
 * @args: A list of variadic arguments
 * Return: Number of characters printed
 */
int print_percent(va_list args);

/**
 * print_d - prints an integer
 * @args: A list of variadic arguments
 * Return: Number of characters printed
 */
int print_d(va_list args);

/**
 * print_i - prints an integer
 * @args: A list of variadic arguments
 * Return: Number of characters printed
 */
int print_i(va_list args);

/**
 * _printf - prints a formatted string
 * @format: The format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...);

#endif /* _MAIN_H_ */
