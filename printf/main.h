#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void print_f(va_list element);

/**
 * _printf: Prototype function for printf
 *
 */

int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_percent(va_list args);
int print_d(va_list args);
int print_i(va_list args);
int _putchar(char c); 

#endif /* _MAIN_H_ */
