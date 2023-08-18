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

#endif /* _MAIN_H_ */
