#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
/**
 * _printf - prints formatted output to stdout
 * @format: the format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	/*
	*if (format == NULL)
	*	return (-1);
	*/
	return (print_buf(format, args));
	va_end(args);
}
