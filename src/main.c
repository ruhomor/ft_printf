#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
//	printf("minus %+f %i\n", +0, ft_if_zero_minus(+0.0));
//	printf("minus %+f %i", -0.0, ft_if_zero_minus(-0.0));



	printf("{%.*s}\n", -5, "42");
	ft_printf("{%.*s}\n", -5, "42");
	printf("{%.*d}\n", -5, 42);
	ft_printf("{%.*d}\n", -5, 42);
	printf("{%.s}\n", "42");
	ft_printf("{%.s}\n", "42");
	printf("original: emem %f %lf %Lf meme\n", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242);
	ft_printf("myprintf: emem %f %lf %Lf meme\n", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242);
//	printf("original: emem %0+5d meme\n", 42);
//	ft_printf("myprintf: emem %0+5d meme\n", 42);
//	printf("{%d}\n", printf("\033[1;32mTest 33 => \033[0m|%#9.o|", 42));
//    ft_printf("{%d}\n", ft_printf("\033[1;31mTest 33 => \033[0m|%#9.o|", 42));
//	printf("{%d}\n", printf("\033[1;32mTest 24 => \033[0m|%#-9.5x|", 42));
//	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 24 => \033[0m|%#-9.5x|", 42));
//	printf("{%d}\n", printf("\033[1;32mTest 25 => \033[0m|%#9.5x|", 42));
//	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 25 => \033[0m|%#9.5x|", 42));
//	printf("{%d}\n", printf("\033[1;32mTest 26 => \033[0m|%#-9.5x|", 2));
//	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 26 => \033[0m|%#-9.5x|", 2));
//	printf("{%d}\n", printf("\033[1;32mTest 27 => \033[0m|%#9.5x|", 2));
//	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 27 => \033[0m|%#9.5x|", 2));
//	printf("{%d}\n", printf("\033[1;32mTest 43 => \033[0m|%#9.2x|", 1234));
//	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 43 => \033[0m|%#9.2x|", 1234));
//	printf("{%d}\n", printf("\033[1;32mTest 24 => \033[0m|%#-9.5o|", 42));
//	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 24 => \033[0m|%#-9.5o|", 42));
//	printf("{%d}\n", printf("\033[1;32mTest 5 => \033[0m|%#.o|", 0));
//	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 5 => \033[0m|%#.o|", 0));
//	printf("{%d}\n", printf("\033[1;32mTest own => \033[0m|%.o|", 0));
//	ft_printf("{%d}\n", ft_printf("\033[1;31mTest own => \033[0m|%.o|", 0));
//
//	printf("{%d}\n", printf("\033[1;32mTest 5 => \033[0m|%#.x|", 0));
//	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 5 => \033[0m|%#.x|", 0));
//	printf("{%d}\n", printf("\033[1;32mTest own => \033[0m|%.x|", 0));
//	ft_printf("{%d}\n", ft_printf("\033[1;31mTest own => \033[0m|%.x|", 0));
//	return (0);
}
