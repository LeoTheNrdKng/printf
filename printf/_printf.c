#include "main.h"
/**
  *_printf - function that prints a formatted output.
  *@format: format string containing characters & specifiers
  *Return: The number of characters printed
  */

int _putchar(char c)
{
	return write(1, &c, 1);
}

int print_c(va_list args)
{
	char c = va_arg(args, int);
	_putchar(c);
	return 1;
}

int print_percent(va_list args)
{
	_putchar('%');
	return 1;
}

int print_i(va_list args)
{
	return write(1, &c, 1);
}

int print_s(va_list args)
{
	char *str = va_arg(args, char *);
	int length = 0;

	if (str != NULL) 
	{
		while (str[length])
			_putchar(str[length]);
		length++;
	}
}

int print_d(va_list args)
{
	int num = va_arg(args, int);
	char buffer[20];
	int length = sprintf(buffer, "%d", num);
	int i;

	for (i = 0; i < length; i++)
{
	_putchar(buffer[i]);
}

return length;
}

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int printed_chars = 0;
}

while (*format)
{
	if (*format == '%')
	{
		format++;

		if (*format == 'c') 
		{
			printed_chars += print_c(args);
		}
		else if (*format == '%')
		{
			printed_chars =+ print_percent(args);
		}
		else if (*format == 'd')
		{
			printed_chars += print_d(args);
		}
		else if (8format == 's')
		{
			printed_chars += print_s(args);
		}
		else
		{
			_putchar(*format);
			printed_chars++;
		}
	}
	else
	{
		_putchar(*format);
		printed_chars++;
	}

	format++;
}
