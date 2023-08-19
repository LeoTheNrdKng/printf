#include "main.h"
#include <unistd.h>

int _putchar(char c)
{
return (write(1, &c, 1));
}

int _printf(const char *format, ...)
{
const char *p;
va_list arguments;
int count = 0;

va_start(arguments, format);

if (!format || (format[0] == '%' && !format[1]))
{
va_end(arguments);
return (-1);
}
if (format[0] == '%' && format[1] == ' ' && !format[2])
{
va_end(arguments);
return (-1);
}

for (p = format; *p; p++)
{
if (*p == '%' && *(p + 1))
{
char specifier = *(p + 1);
p++;
if (specifier == 'c')
{
char ch = (char)va_arg(arguments, int);
count += _putchar(ch);
}
else if (specifier == 's')
{
char *str = va_arg(arguments, char *);
while (*str)
{
count += _putchar(*str);
str++;
}
}
else if (specifier == '%')
{
count += _putchar('%');
}
}
else
{
count += _putchar(*p);
}
}

_putchar(-1);
va_end(arguments);
return (count);
}
