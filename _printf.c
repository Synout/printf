#include "main.h"

/**
 * _printf - prints formatted string
 * @f: formatter
 * @... : chars to be printed
 * Return : int
 */ 

int _printf(const char *format, ...);
void clean(va_list args, buffer_t *output);
int printf_exec(const char *format, va_list args, buffer_t *output);

void clean(va_list args, buffer_t *output)
{
va_end(args);
write(1, output->start, output->len);
free_buffer(output);
}
/**
 * printf_exec - 
 *
 *
 *
 *
 */

int printf_exec(const char *format, va_list args, buffer_t *output)
{
char temp;
int rtn =0;
int i =0;
int wid = 0;
int prec = 0;
unsigned char flags, len;
unsigned int (*spec)(va_list, buffer_t *, unsigned char, int, int, unsigned char);
for (temp = 0; *(format + i); i++)
{
len = 0;
if (*(format + i) == '%')
{
prec = prec_handle(args, format + i + temp + 1, &temp);
flags = flags_handle(format + i + 1, &temp);
wid = wid_handle(args, format + i + temp + 1, &temp);
len = len_handle(format + i + temp +1, &temp);
spec = spec_handle(format + i + temp + 1);
if (spec != NULL)
{
i += temp + 1;
rtn += spec(args, output, flags, wid, prec, len);
continue;
}
else if (*(format + i + temp + 1) == '\0')
{
rtn = -1;
break;
}
}
rtn += _memcpy(output, (format + i), 1);
i += (len != 0) ? 1 : 0;
}
clean(args, output);
return (rtn);
}

int _printf(const char *format, ...)
{
buffer_t *output;
va_list args;
int rtn;

if (format == NULL)
{
return (-1);
}
output = init_buffer();
if (output == NULL)
{
return (-1);
}
va_start(args, format);
rtn = printf_exec(format, args, output);

return (rtn);

}
