#include "main.h"

/**
 * _size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @li: list of arguments.
 * Return: Precision.
 */
int _size(const char *format, int *i)
{
	int curr_int = *i + 1;
	int size = 0;

	if (format[curr_int] == 'l')
		size = S_LONG;
	else if (format[curr_int] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_int - 1;
	else
		*i = curr_int;

	return (size);
}
