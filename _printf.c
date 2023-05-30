#include "main.h"

/**
 * _printf-print as the printf lib
 * @format:first string
 * Return:arguments.
 */
int _printf(const char *format, ...)
{
	int i, p_char = 0, str = 0;

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
