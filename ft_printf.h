
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_print
{
	va_list args;
	int widht;
	int prc;
	int zero;
	int pnt;
	int dash;
	int len;
	int sign;
	int is_zero;
	int perc;
	int sp;
}	t_print;

int		ft_process(va_list *ap, const char format);
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *c);
int		ft_putnbr(int n);
int		ft_putptr(unsigned long  ptr);
int		ft_printptr(unsigned long num);
int		ft_putunsigned(unsigned int num);
int		ft_puthex(unsigned int num, const char format);

#endif