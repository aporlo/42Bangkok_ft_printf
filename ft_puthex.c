#include "ft_printf.h"

int	ft_puthex(unsigned num, const char format)
{
	int	length;
	
	length = 0;
	if (num < 16)
	{
		if (num > 9 && format == 'x')
		{
			length += ft_putchar(num + 87);
        }
		else if (num > 9 && format == 'X')
		{
			length += ft_putchar(num + 55);
		}
		else
			length += ft_putchar(num + 48);
	}
	else if (num >= 16)
	{
		length += ft_puthex(num / 16, format);
		length += ft_puthex(num % 16, format);
	}
	return (length);
}
