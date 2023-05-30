#include "main.h"

void _buffer(char buffer[], int *buff_int);

/**
 * _printf-print as the printf lib
 * @format:first string
 * Return:arguments.
 */
int _printf(const char *format, ...)
{
	int i, p_char = 0, str = 0;
	int flags, width, precision, size, buff_int = 0;
	va_list li;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(li, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_int++] = format[i];
			if (buff_int == BUFF_SIZE)
				_buffer(buffer, &buff_int);
			p_char++;
		}
		else
		{
			_buffer(buffer, &buff_int);
			flags = _flags(format, &i);
			width = _width(format, &i, li);
			precision = _precision(format, &i, li);
			size = _size(format, &i);
			++i;
			str = _handle(format, &i, li, buffer,
				flags, width, precision, size);
			if (str == -1)
				return (-1);
			p_char += str;
		}
	}

	_buffer(buffer, &buff_int);

	va_end(li);

	return (p_char);
}

/**
 * _buffer-Prints the char in a buffer
 * @buffer:array of char
 * @buff_int:len of a buffer
 */
void _buffer(char buffer[], int *buff_int)
{
	if (*buff_int > 0)
		write(1, &buffer[0], *buff_int);

	*buff_int = 0;
}
