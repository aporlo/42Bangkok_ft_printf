
#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"


// type struct s_sc
// {
// 	int len;
// 	int widht;
// }			t_sc;

// int ft_printf(const char	*format, ...)
// {
// 	va_list	arg;
// 	va_start(arg, format);
// 	t_sc sc;
// 	sc.len = 0;
// 	sc.widht = 0;
// }

t_print *ft_init_tab(t_print *tab)
{
	tab->widht = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->dash = 0;
    tab->len = 0;
    tab->sign = 0;
    tab->is_zero = 0;
    tab->perc = 0;
    tab->sp = 0;
    return (tab);	
}

int ft_printf(const char *format, ...)
{
	t_print	*tab;
    int i;
    int res;
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_init_tab(tab);
    va_start (tab->args, format);
    i = -1;
    res = 0;
    while (format[++i])
    {
        if (format[i] == '%')
            // i = ft_eva_format(tab, format, i + 1);
            return (0);
        else
            res += write(1, &format[i], 1);
        if (!format[++i])
        {
            res += write(1, "(null)", 6);
            va_end(tab->args);
            return(res);
        }      
    }
    va_end(tab->args);
    res += tab->len;
    free(tab);
    return(res);
}
