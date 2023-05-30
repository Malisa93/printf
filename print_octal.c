#include "main.h"
/**
 * convert_u - Prints unsiged integer
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
 * Return:unsiged integer
 *
 */

int convert_u(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * convert_o - Prints an integer octal
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
 * Return:an interger in octal
 *
 */

int convert_o(va_list types, char buffer[],
	int flags, int width, int precision, int size)
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
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && num_init != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
