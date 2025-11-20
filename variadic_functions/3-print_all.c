#include "variadic_functions.h"

/**
 * print_char - Print a char from var args.
 * @list: va_list to print from.
 */
void print_char(va_list list)
{
	printf("%c", va_arg(list, int));
}

/**
 * print_int - Print an int from var args.
 * @list: va_list to print from.
 */
void print_int(va_list list)
{
	printf("%d", va_arg(list, int));
}

/**
 * print_float - Print a float from var args.
 * @list: va_list to print from.
 */
void print_float(va_list list)
{
	printf("%f", va_arg(list, double));
}

/**
 * print_string - Print a string, prints (nil) if NULL.
 * @list: va_list to print from.
 */
void print_string(va_list list)
{
	char *string = va_arg(list, char *);

	if (string == NULL)
	{
		string = "(nil)";
	}

	printf("%s", string);
}

/**
 * print_all - A function that prints anything :)
 * @format: format string.
 */
void print_all(const char * const format, ...)
{
	int format_index = 0;
	int printer_index = 0;
	char *separator = "";

	va_list list;

	checker printers[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string},
		{NULL, NULL}
	};

	va_start(list, format);

	while (format != NULL && format[format_index] != '\0')
	{
		while (printer_index < 4)
		{
			if (format[format_index] == *printers[printer_index].type)
			{
				printf("%s", separator);
				printers[printer_index].function(list);
				separator = ", ";
			}
			printer_index++;
		}

		format_index++;
		printer_index = 0;
	}

	printf("\n");
	va_end(list);
}
