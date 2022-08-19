
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

int	ft_printf(const char *format, ...);

#endif