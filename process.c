#include "main.h"

/**
 * process_format - Processes and handles formatted input arguments.
 * @format: A pointer to the format string containing conversion specifiers.
 * @args: A va_list containing the variable arguments.
 * @count: A pointer to an integer to store the count of characters printed.
 */
void process_format(const char *format, va_list args, int *count)
{
int num;
unsigned int u_num;
char buffer[20];
char u_buffer[20];

switch (*format)
{
case 'c':
handle_char(args, count);
break;
case 's':
handle_string(args, count);
break;
case '%':
handle_percent(count);
break;
case 'd':
case 'i':
num = va_arg(args, int);
{
int len = snprintf(buffer, sizeof(buffer), "%d", num);
write(1, buffer, len);
*count += len;
}
break;
case 'u':
u_num = va_arg(args, unsigned int);
{
int u_len = snprintf(u_buffer, sizeof(u_buffer), "%u", u_num);
write(1, u_buffer, u_len);
*count += u_len;
}
break;
case 'b':
u_num = va_arg(args, unsigned int);
{
int b_len = print_binary(u_num);
*count += b_len;
}
break;
default:
write(1, format - 1, 2);
*count += 2;
}
}
