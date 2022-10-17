#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct buffer_s
{
char *buff;
char *start;
unsigned int len;
} buffer_t;


buffer_t *init_buffer(void);
void free_buffer(buffer_t *output);
int _printf(const char *format, ...);
int wid_handle(va_list args, const char *modifier, char *index);
int prec_handle(va_list args, const char *modifier, char *index);
int len_handle(const char *modifier, char *index);
unsigned int (*spec_handle(const char *specifier))(va_list, buffer_t *, unsigned char, int, int, unsigned char);
unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n);
unsigned char flags_handle(const char *flags, char *index);

#endif 


