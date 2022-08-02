#include <stdarg.h>
#include <stdio.h>

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

 
void variadic_funct(int count, ...)
{
    va_list args;
    int i;
    va_start(args, count);
    printf ("variadic : argument count = %d\n", count);
    for (i = 0; i < count; i++) {
     printf("argument %d = %d, ", i + 1, va_arg(args, int));
    }
    printf ("\n");
    va_end(args);
}
 
int main(void)
{
    variadic_funct(0); 
    variadic_funct(1,10);
    variadic_funct(2,10,20);
    variadic_funct(2,10,20,30);  
}