#include "main.h"

/**
 * _precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @li: list of arguments.
 * Return: Precision.
 */
int _precision(const char *format, int *i, va_list li)
{
	int curr_int = *i + 1;
	int prec = -1;

	if (format[curr_int] != '.')
		return (prec);

	prec = 0;

	for (curr_int += 1; format[curr_int] != '\0'; curr_int++)
	{
		if (is_digit(format[curr_int]))
		{
			prec *= 10;
			prec += format[curr_int] - '0';
		}
		else if (format[curr_int] == '*')
		{
			curr_int++;
			prec = va_arg(li, int);
			break;
		}
		else
			break;
	}

	*i = curr_int - 1;

	return (prec);
}
