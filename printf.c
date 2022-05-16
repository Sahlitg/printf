#include <stdio.h>
#include <stdarg.h>
#include <main.h>

int printIdentifier(char next, va_list arg)
{
	int functsIndex;

	identifierStruct functs[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_int},
		{"i", print_int},
		{"u", print_unsigned},
		{"b", print_unsignedToBinary},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_STR},
		{NULL, NULL}
	};

	for (functsIndex = 0; functs[functsIndex].indentifier != NULL; functsIndex++)
	{
		if (functs[functsIndex].indentifier[0] == next)
			return (functs[functsIndex].printer(arg));
	}
	return (0);
}


int _printf(const char *format, ...);
{
	unsigned int i;
	int identifierPrinted = 0, charprinted = 0;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			charPrinted++
			continue;
		}
		if (format[i + 1] == '%')
		{
			_putchar('%');
			charPrinted++
		        i++;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);

		identifierPrinted = printIdentifier(format[i + 1], arg);
		if (identifierPrinted == -1 || identifierPrinted != 0)
			i++;
		if (identifierPrinted > 0)
			charPrinted += identifierPrinted;

		if (identifierPrinted == 0)
		{
			_putchar('%');
			charPrinted++
		}
	}
	va_end(arg);
	return (charPrinted);
}
