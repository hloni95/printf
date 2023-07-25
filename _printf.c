#include <stdio.h>
#include <stdarg.h>

void my_printf(const char* c, ...)
{
    va_list args;
    va_start(args, format);

    char ch;
    for (size_t i = 0; format[i] != '\0'; ++i)
    {
        if (format[i] == '%')
	{
            ++i;
            switch (format[i]) 
	    {
                case 'c':
                    ch = va_arg(args, int);
                    putchar(ch);
                    break;
                case 's':
                    puts(va_arg(args, const char*));
                    break;
                default:
                    putchar('%');
                    putchar(format[i]);
            }
        }
	else
	{
            putchar(format[i]);
        }
    }

    va_end(args);
}
