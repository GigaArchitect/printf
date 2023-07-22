#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
/**
 * print_buf - prints formatted output to stdout
 * @format: the format string
 *
 * Return: the number of characters printed
 */
int print_buf(const char *format, ...)
{
	int i, length = 0;
	va_list args;

	va_start(args, format);
	for (i = 0; i < (int)strlen(format); i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				length += 1;
				i += 1;
			}
			else if (format[i + 1] == 's')
			{
				char *s = va_arg(args, char*);

				write(1, s, strlen(s));
				length += strlen(s);
				i += 1;
			}
			else if (format[i + 1] == '%')
			{
				write(1, "%", 1);
				length += 1;
				i += 1;
			}
		}
		else
		{
			write(1, &format[i], 1);
			length += 1;
		}
	}
	va_end(args);
	return (length);
}
