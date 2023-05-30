#include "main.h"

/**
 * _flags -This Calculates active flags
 *
 * @format: The Formatted string in which to print the arguments
 *
 * @i: take a parameter
 *
 * Return: Flags
 *
 */

int _flags(const char *format, int *i)
{
	int j, curr_int;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_int = *i + 1; format[curr_int] != '\0'; curr_int++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_int] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_int - 1;

	return (flags);
}
