#include "main.h"
/**
 * convert_x- Prints a hexadecimal
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
 * Return:hexadecimal value
 *
 */

int convert_x(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * convert_X- Prints a hexadecimal in upper case
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
 * Return:hexadecimal value in upper case
 *
 */

int convert_X(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
	flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 *
 * @types: List of arguments
 *
 * @map_to:map the array of value
 *
 * @buffer:Buffer array to handle print
 *
 * @flags:Calculates active flags
 *
 * @flag_ch:Calculates active flags
 *
 * @width:width
 *
 * @precision:Precision
 *
 * @size:Size
 *
 * @size:Size
 *
 * Return: Number in lower and upper hexa-decimal
 *
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int num_init = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && num_init != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
