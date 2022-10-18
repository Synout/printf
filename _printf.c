#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}


/**
 * _printf - prints formatted string
 * @f: formatted string
 * @... : char formats/variables
 * Return : int, 0 if succesful else NULL
 */ 

int _printf(const char *format, ...)
{
int i = 0;
int j;

va_list args;
va_start(args, format);

for (; format[i];)
{
if (format[i] == '%')
{
i++;
/*Check the formatter */
switch(format[i])
{
case 'c':
{
char *c = va_arg(args, char*);
_putchar(*c);
break;
}
case 's':
{
char *c[999];
*c = va_arg(args, char*);
for (j = 0; *c[j] != '\0'; j++)
{
_putchar(*c[j]);
}
break;
}
default:
{
_putchar('%');
_putchar(format[i]);
break;
}
}
}
else if (format[i] == '\0')
{
break;
}
else
{
_putchar(format[i]);
}
i++;
}
return (0);
}
