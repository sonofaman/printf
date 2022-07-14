#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

unsigned int _strlen(const char *str);
int _print(const char *format, va_list args);
int _print_num(size_t num, size_t base);

/**
 * _printf - A function that mimics the traditional c printf
 * @format: The string to be printed
 * Return: The length of the characters printed in int
 */

int _printf(const char *format, ...)
{
	int length;
	va_list args;

	if (format == NULL)
		return (0);
	va_start(args, format);
	length = _print(format, args);
	va_end(args);
	return (length);
}

/**
 * _print - The helper function that implements
 * the print and formatting
 * @format: The string to be printed
 * @arg: These are additional args which may be 0 or more and it's
 * of type va_list
 * Return: it returns an int... the number of characters
 * printed
 */
int _print(const char *format, va_list arg)
{
	char *s;
	size_t i;
	int dec;
	int length;
	unsigned int idx, len = _strlen(format);
	
	if (format == NULL)
		return (-1);
	length = 0;
	idx = 0;
	while (idx < len)
	{
		while (format[idx] != '%' && idx < len)
		{
			_putchar(format[idx]);
			length++;
			idx++;
		}
		idx++;
		if (idx >= len)
			break;

		switch (format[idx])
		{
			case 's':
				s = va_arg(arg, char *);
				while (*s != '\0')
				{
					_putchar(*s++);
					length++;
				}
				break;
			case 'c':
				i = va_arg(arg, int);
				_putchar(i);
				length++;
				break;
			case '%':
				_putchar(format[idx]);
				length++;
				break;
			case 'd':
			case 'i':
				dec = va_arg(arg, int);
				if (dec < 0)
				{
					_putchar('-');
					dec = -1 * dec;
					length++;
					length += _print_num(dec, 10);
				}
				else
				{
					length += _print_num(dec, 10);
				}
				break;
			case 'b':
				dec = va_arg(arg, int);
				length += _print_num(dec, 2);
				break;
			default:
				return (0);
		}
		idx++;
	}
	return (length);
}

/**
 * _strlen - A function that finds the length of a string
 * @str: The string
 * Return: The length
 */
unsigned int _strlen(const char *str)
{
	unsigned long int i, length;

	i = 0;
	length = 0;
	while (str[i++] != '\0')
		length++;
	return (length);

}

/**
 * _print_num - prints numbers in their desired base.
 * @num: The number to be printed
 * @base: The base to be printed
 * Return: int
 */
int _print_num(size_t num, size_t base)
{
	int length, i, mod;

	i = num / base;
	mod = num % base;
	length = 1;

	if (i > 0)
	{
		length += _print_num(i, base);
	}
	else
	{
		_putchar(mod + '0');
		return (1);
	}
	_putchar(mod + '0');
	return (length);
}
