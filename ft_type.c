#include "ft_printf.h"

char	ft_gettypeflag(char type)
{
	if (type == '0')
		return ('0');
	else if (type == '#')
		return ('#');
	else if (type == '+')
		return ('+');
	else if (type == '-')
		return ('-');
	else if (type == '.')
		return ('.');
	else if (type == '*')
		return ('*');
	else if (type == ' ')
		return (' ');
	else
		return ('\0');
}

void	ft_plus(int d, char type, int param, char *format)
{
	int		d_width;
	char	add_type;
	char	add_type_value;

	d_width = param - ft_nbrlen(d);
	add_type = format[ft_chrpos(format, type) + 1];
	add_type_value = format[ft_chrpos(format, type) + 2];
	if (type == '+' && add_type != '0')
	{
		if (d_width)
			ft_fill(d_width, ' ');
		if (d > 0)
			ft_putchar('+');
		ft_putnbr(d);
	}
	if (type == '+' && add_type == '0')
	{
		d *= -1;
		ft_putchar('-');
		if (add_type_value != '1')
			ft_putchar('0');
		ft_putnbr(d);

	}
}

void	ft_minus(int d, char type)
{
	if (type == '-')
		ft_putndr(d);
}

void	ft_spaceflag(int d, char type, int param)
{
	if (type == ' ' && (param < 0) && d > 0)
		ft_putchar(' ');
	if (flag == ' ' && param)
	{
		ft_fill((param - ft_nbrlen(d)), ' ');
		ft_putnbr(d);
	}
}

void	ft_zero(int d, char type)
{
	if (flag == '0' && d < 0)
	{
		d *= -1;
		ft_putchar('-');
		ft_putchar('0');
		ft_putnbr(d);
	}
}
