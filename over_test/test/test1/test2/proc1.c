#include "main.h"

/**
 * process_format - Processes and handles formatted input arguments.
 * @format: A pointer to the format string containing conversion specifiers.
 * @args: A va_list containing the variable arguments.
 * @count: A pointer to an integer to store the count of characters printed.
 */
void process_format(const char *format, va_list args, int *count)
{
	(void)format; /* Parameter intentionally unused */
	int num;
	unsigned int u_num;

	char current_format = *(format + 1);

	switch (current_format)
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
			process_int(num, count);
			break;
		case 'u':
			u_num = va_arg(args, unsigned int);
			process_unsigned(u_num, count);
			break;
		case 'b':
			u_num = va_arg(args, unsigned int);
			process_binary(u_num, count);
			break;
		default:
			write(1, format - 1, 2);
			*count += 2;
	}
}
