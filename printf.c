#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
/**
 * _printf - does a part of printf’s function
 * @format: format string
 *
 * Return: number of characters printed excluding null byte
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

const char *ptr;

char *str;

va_start(args, format);
for (ptr = format; *ptr != '\0'; ptr++)
{
if (*ptr == '%' && *(ptr + 1) != '\0')
{
ptr++;
switch (*ptr)
{
case 'c':
count += write(1, va_arg(args, int), 1);
break;
case 's':
str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
count += write(1, str, _strlen(str));
break;
case '%':
count += write(1, "%", 1);
break;
default:
count += write(1, "%", 1);
count += write(1, &(*ptr), 1);
break;
}
}
else
{
count += write(1, &(*ptr), 1);
}
}
va_end(args);
return (count);
}
/**
 * _strlen - calculates the length of a string
 * @str: string to check
 *
 * Return: length of string
 */
int _strlen(const char *str)
{
int length = 0;
while (str[length] != '\0')
{
length++;
}
return length;
}
