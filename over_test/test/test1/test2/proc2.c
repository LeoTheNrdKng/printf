#include "main.h"

/**
 * process_int - Handles integer conversion specifier.
 * @format: Format specifier (unused).
 * @args: A va_list containing the variable arguments.
 * @count: A pointer to an integer to store the count of characters printed.
 */
void process_int(const char *format, va_list args, int *count)
{
	(void)format; /* Parameter intentionally unused */
	int num = va_arg(args, int);
	char buffer[20];
	int len = snprintf(buffer, sizeof(buffer), "%d", num);

	write(1, buffer, len);

	*count += len;
}
