#include "ft_printf.h"

void	ft_putnbr(int *n)
{
	int		i;

	if (*n == -2147483648)
	{
		write(1, -2147483648, 11);
		i = 11;
	}
	else if (*n < 0)
	{
		i += ft_putchar('-');
		n = *n * -1;
		i += ft_putnbr(*n);
	}
	else if (*n > 9)
	{
		i += ft_putnbr(*n / 10);
		i += ft_putnbr((*n % 10) );
	}
	else
		i += ft_putchar(*n + 48);
}
