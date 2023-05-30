#include "main.h"

/**
 * convert_c - Prints a character
 *
 * @types: List of arguments
 *
 * @buffer: Buffer array to handle print
 *
 * @flags:flags
 *
 * @width:Width
 *
 * @precision:Precision
 *
 * @size:Size
 *
 * Return:a char
 *
 */

int convert_c(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * convert_s - Prints a string
 *
 * @types: List of arguments
 *
 * @buffer: Buffer array to handle print
 *
 * @flags:flags
 *
 * @width:Width
 *
 * @precision:Precision
 *
 * @size:Size
 *
 * Return:a string
 *
 */

int convert_s(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, len = 0;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}

/**
 * convert_percent - Prints a percentage
 *
 * @types: List of arguments
 *
 * @buffer: Buffer array to handle print
 *
 * @flags:flags
 *
 * @width:Width
 *
 * @precision:Precision
 *
 * @size:Size
 *
 * Return:a percentage
 *
 */

int convert_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
