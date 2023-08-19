#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...)
{
va_list args;
int count = 0;
int num;
unsigned int u_num;
char buffer[20];
char u_buffer[20];

va_start(args, format);

while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
break;
case 's':
break;
case '%':
write(1, "%", 1);
count++;
break;
case 'd':
case 'i':
num = va_arg(args, int);
{
int len = snprintf(buffer, sizeof(buffer), "%d", num);
write(1, buffer, len);
count += len;
}
break;
case 'u':
u_num = va_arg(args, unsigned int);
{
int u_len = snprintf(u_buffer, sizeof(u_buffer), "%u", u_num);
write(1, u_buffer, u_len);
count += u_len;
}
break;
default:
write(1, format - 1, 2);
count += 2;
}
}
else
{
write(1, format, 1);
count++;
}
format++;
}

va_end(args);
return (count);
}
