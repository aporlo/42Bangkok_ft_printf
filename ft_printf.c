
#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int ft_process(va_list *ap, const char format)
{
    int         len;

    len = 0;
    if (format == 'c')
        len += ft_putchar(va_arg(*ap, int));
    else if (format == 's')
        len += ft_putstr(va_arg(*ap, char *));
    else if (format == 'p')
        len += ft_putptr(va_arg(*ap, unsigned long));
    else if (format == 'd' || format == 'i')
        len += ft_putnbr(va_arg(*ap, int));
    else if (format == 'u')
        len += ft_putunsigned(va_arg(*ap, unsigned int));
    else if (format == 'x' || format == 'X')
        len += ft_puthex(va_arg(*ap, unsigned int), format);
    else if (format == '%')
        len += ft_putchar('%');
    return (len);
}

int    ft_putchar(char c)
{
    return write(1, &c, 1);
}

int ft_printf(const char *format, ...)
{
    int         i;
    int         len;
    va_list ap;

    i = 0;
    len = 0;
    va_start(ap, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            len = len + ft_process(&ap, format[i + 1]);
            i++;
        }
        else
            len = len + ft_putchar(format[i]);
            i++;
    }
    
    va_end(ap);
    return (len);
}

