#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct spec-Struct
 * @spec:format.
 * @func:function.
 */
struct spec
{
	char spec;
	int (*func)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 * @spec:format.
 * @fm_t:function
 */
typedef struct spec fmt_t;

int _printf(const char *format, ...);
int _handle(const char *spec, int *x, va_list li, char buffer[],
	int width, int size, int precision, int flags);

/* prototype function to print character */
int convert_c(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int convert_s(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int convert_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* prototype functions to print numbers */
int convert_d(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int convert_b(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int convert_u(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int convert_o(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int convert_x(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int convert_X(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* prototype function to print non printable characters */
int convert_S(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* prototype for a ponter*/
int convert_p(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*prototypes for flags*/
int _flags(const char *format, int *i);
int _width(const char *format, int *i, va_list li);
int _precision(const char *format, int *i, va_list li);
int _size(const char *format, int *i);

/*prototype for reverse string*/
int convert_r(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*prototype to print a string in rot 13*/
int convert_R(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);


int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
