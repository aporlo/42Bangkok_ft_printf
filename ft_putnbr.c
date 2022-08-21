#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		i;
	
	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		i = 11;
	}
	else if (n < 0)
	{
		i = i + ft_putchar('-');
		n = -n;
		i = i + ft_putnbr(n);
	}
	else if (n > 9)
	{
		i = i + ft_putnbr(n / 10);
		i = i + ft_putnbr(n % 10);
	}
	else
		i = i + ft_putchar(n + 48);
	return (i);
}
