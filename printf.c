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

char *str, c;

va_start(args, format);
for (ptr = format; *ptr != '\0'; ptr++)
{
if (*ptr == '%' && *(ptr + 1) != '\0')
{
ptr++;
switch (*ptr)
{
case 'c':
c = (char)va_arg(args, int);
count += write(1, &c, 1);
break;
case 's':
str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
count += write(1, str, _strlen(str));
break;
case 'd':
case 'i':
print_int(va_arg(args, int));
break;
case 'b':
print_binary(va_arg(args, unsigned int));
break;
case '%':
count += write(1, "%", 1);
break;
default:
count += write(1, "%", 1) + write(1, ptr, 1);
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
return (length);
}
/**
 * print_int - prints an integer
 * @num: integer to print
 */
void print_int(int num)
{
char buffer[15];

int i = 0;

if (num == 0)
{
write(1, "0", 1);
return;
}
if (num < 0)
{
write(1, "-", 1);
num = -num;
}
while (num != 0)
{
buffer[i++] = '0' + num % 10;
num /= 10;
}
while (i > 0) {
write(1, &buffer[--i], 1);
}
}
void print_binary(unsigned int num)
{
int i;

char binary_digits[64];
for (i = 64 - 1; i >= 0; i--)
{
binary_digits[i] = '0' + (num & 1);
num >>= 1;
}
write(1, binary_digits, 64);
}
