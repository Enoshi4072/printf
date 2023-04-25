#include <stdio.h>
#include <stdarg.h>

#include <unistd.h>

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
 * _printf - prints formatted output
 * @format: format string
 *
 * Return: number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);

int count = 0;
while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
char c = (char) va_arg(args, int);
putchar(c);
count++;
}
else if (*format == 's')
{
char *s = va_arg(args, char*);
while (*s != '\0')
{
putchar(*s);
s++;
count++;
}
}
else if (*format == '%')
{
putchar('%');
count++;
}
}
else
{
putchar(*format);
count++;
}
format++;
}
va_end(args);
return count;
}
