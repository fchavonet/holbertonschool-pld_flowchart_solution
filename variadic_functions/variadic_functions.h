#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct formats - Structure linking a format type to a print function.
 * @type: pointer to a string representing the type (ex: "c", "i", "f", "s").
 * @function: function pointer that prints the corresponding argument.
 */
typedef struct formats
{
	char *type;
	void (*function)(va_list);
} checker;

/* Prototypes for helper print functions. */
void print_char(va_list list);
void print_int(va_list list);
void print_float(va_list list);
void print_string(va_list list);

/* Prototype for main variadic function. */
void print_all(const char * const format, ...);

#endif /* VARIADIC_FUNCTIONS_H */
