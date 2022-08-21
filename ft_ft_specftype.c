#include "ft_printf.h"

void	ft_speciftypeinit(char *format, char specif, char flag, va_list ap)
{
	if (specif == 'c' || specif == 'C')
		ft_c(ap, format, flag);
	else if (specif == 's' || specif == 'S')
		ft_s(ap, format, flag);
	else if (specif == 'p')
		ft_p(ap);
	else if (specif == 'd' || specif == 'D')
		ft_d(ap, format, flag);
	else if (specif == 'x' || specif == 'X')
		ft_x(sp, format, flag);
	else if (specif == 'i')
		ft_i(ap, format, flag);
	else if (specif == 'o' || specif == 'O')
		ft_o(ap, format, flag);
	else if (specif == 'u' || specif == 'U')
		ft_u(ap, format, flag);
}

void	ft_c(va_list ap, char *format, char flag)
{
	char	c;
	char	f_addon;
	char	*tmp;
	int		param;
	int		p_addon;

	c = (char)va_arg(ap, int);
	f_addon = format[ft_chrpos(format, flag) + 1];
	tmp = ft_strsub(format, ft_chrpos(format, f_addon), ft_strlen(format) - 2);
	param = ft_getparam(format, flag) - 1;
	p_addon = ft_getparam(tmp, flag) -1;
	if (flag == '+' && f_addon != '-')
		ft_fill(param - 1, ' ');
	if (flag == '0' && f_addon != '+')
		ft_fill(param - 1, ' ');
	if (f_addon == '+' && flag == '0')
		ft_fill(p_addon -1, ' ');
	if (c)
		ft_c_support(c, param, flag, f_addon);
}

void ft_s(va_list ap, char *format, char flag)
