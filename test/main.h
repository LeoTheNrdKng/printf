#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/* Writes a character to stdout. */
int _putchar(char c);

/* Handles the 'c' format specifier. */
void handle_char(va_list arguments, int *count);

/* Handles the 's' format specifier. */
void handle_string(va_list arguments, int *count);

/* Handles the '%%' format specifier. */
void handle_percent(int *count);

/* Handles the 'd' and 'i' format specifiers. */
void handle_integer(va_list arguments, int *count);

/* Handles the 'u' format specifier. */
void handle_unsigned_integer(va_list arguments, int *count);

/* Processes a single format specifier. */
void handle_format(char specifier, va_list args, int *count);

/* Declare process_format function to make it visible in _printf. */
int process_format(const char **format, va_list args, int *count);

/* Custom implementation of the printf function. */
int _printf(const char *format, ...);

#endif /* MAIN_H */
