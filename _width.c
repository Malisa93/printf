#include "main.h"

/**
 * _width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @li: list of arguments.
 * Return: width.
 */
int _width(const char *format, int *i, va_list li)
{
	int curr_int;
	int width = 0;

	for (curr_int = *i + 1; format[curr_int] != '\0'; curr_int++)
	{
		if (is_digit(format[curr_int]))
		{
			width *= 10;
			width += format[curr_int] - '0';
		}
		else if (format[curr_int] == '*')
		{
			curr_int++;
			width = va_arg(li, int);
			break;
		}
		else
			break;
	}

	*i = curr_int - 1;

	return (width);
}
