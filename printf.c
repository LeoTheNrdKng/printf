#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: Format string containing characters and specifiers.
 *
 * Description:
 * This function processes the format string and calls appropriate printing
 * functions based on the conversion specifiers. It also handles flags for
 * formatting options.
 *
 * Return:
 * The total number of characters printed.
 */
int _printf(const char *format, ...)
{
    int (*pfunc)(va_list, flags_t *);
    const char *p;
    va_list arguments;
    flags_t flags = {0, 0, 0};

    register int count = 0;

    va_start(arguments, format);
    if (!format || (format[0] == '%' && !format[1]))
        return (-1);
    if (format[0] == '%' && format[1] == ' ' && !format[2])
        return (-1);
    for (p = format; *p; p++)
    {
        if (*p == '%')
        {
            p++;
            if (*p == 'c') // Character specifier
            {
                char ch = va_arg(arguments, int);
                count += _putchar(ch);
                continue;
            }
            else if (*p == 's') // String specifier
            {
                char *str = va_arg(arguments, char *);
                while (*str)
                {
                    count += _putchar(*str);
                    str++;
                }
                continue;
            }
            else if (*p == '%') // Literal percent symbol
            {
                count += _putchar('%');
                continue;
            }
        }
        count += _putchar(*p);
    }
    _putchar(-1); // Signal the end of printing
    va_end(arguments);
    return (count);
}
