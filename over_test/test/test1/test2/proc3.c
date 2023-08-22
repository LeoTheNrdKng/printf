#include "main.h"

/**
 * process_unsigned - Handles unsigned conversion specifier.
 * @format: Format specifier (unused).
 * @args: A va_list containing the variable arguments.
 * @count: A pointer to an integer to store the count of characters printed.
 */
void process_unsigned(const char *format, va_list args, int *count)
{
	(void)format; /* Parameter intentionally unused */
	unsigned int u_num = va_arg(args, unsigned int);
	char u_buffer[20];
	int u_len = snprintf(u_buffer, sizeof(u_buffer), "%u", u_num);

	write(1, u_buffer, u_len);

	*count += u_len;
}

/**
 * process_binary - Handles binary conversion specifier.
 * @format: Format specifier (unused).
 * @args: A va_list containing the variable arguments.
 * @count: A pointer to an integer to store the count of characters printed.
 */
void process_binary(const char *format, va_list args, int *count)
{
	(void)format; /* Parameter intentionally unused */
	unsigned int u_num = va_arg(args, unsigned int);
	*count += print_binary(u_num);
}
