#include "main.h"
/**
 * _handle-print argument by specifier handler
 * @spec:string to print to argument
 * @x:pointer of a variable
 * @li:list of argument
 * @buffer:container for printing
 * @flags:flags
 * @width:width.
 * @precision:Precision
 * @size:Size
 * Return:1||2;
 */
int _handle(const char *spec, int *x, va_list li, char buffer[],
	int width, int size, int precision, int flags)
{
	int i, un = 0, p_char = -1;
	fmt_t c_str[] = {
		{'c', convert_c},
		{'s', convert_s},
		{'d', convert_d}, {'i', convert_d},
		{'%', convert_percent},
		{'b', convert_b}, {'o', convert_o},
		{'u', convert_u},
		{'x', convert_x},
		{'X', convert_X},
		{'S', convert_S},
		{'p', convert_p},
		{'r', convert_r},
		{'R', convert_R},
		{0, NULL}
	};
	for (i = 0; c_str[i].spec != '\0'; i++)
		if (spec[*x] == c_str[i].spec)
			return (c_str[i].func(li, buffer, flags, width, precision, size));

	if (c_str[i].spec == '\0')
	{
		if (spec[*x] == '\0')
			return (-1);
		un += write(1, "%%", 1);
		if (spec[*x - 1] == ' ')
			un += write(1, " ", 1);
		else if (width)
		{
			--(*x);
			while (spec[*x] != ' ' && spec[*x] != '%')
				--(*x);
			if (spec[*x] == ' ')
				--(*x);
			return (1);
		}
		un += write(1, &spec[*x], 1);
		return (un);
	}
	return (p_char);
}
