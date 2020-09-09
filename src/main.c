#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{

//	printf("original: emem %0.10hhx meme\n", 98123456);
//	ft_printf("myprintf: emem %0.10hhx meme\n", 98123456);
//	printf("original: emem %ho meme\n", -12342283221488);
//	ft_printf("myprintf: emem %ho meme\n", -12342283221488);
	printf("{%d}\n", printf("\033[1;32mTest 33 => \033[0m|%#9.o|", 42));
    ft_printf("{%d}\n", ft_printf("\033[1;31mTest 33 => \033[0m|%#9.o|", 42));
	printf("{%d}\n", printf("\033[1;32mTest 24 => \033[0m|%#-9.5x|", 42));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 24 => \033[0m|%#-9.5x|", 42));
	printf("{%d}\n", printf("\033[1;32mTest 25 => \033[0m|%#9.5x|", 42));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 25 => \033[0m|%#9.5x|", 42));
	printf("{%d}\n", printf("\033[1;32mTest 26 => \033[0m|%#-9.5x|", 2));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 26 => \033[0m|%#-9.5x|", 2));
	printf("{%d}\n", printf("\033[1;32mTest 27 => \033[0m|%#9.5x|", 2));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 27 => \033[0m|%#9.5x|", 2));
	printf("{%d}\n", printf("\033[1;32mTest 43 => \033[0m|%#9.2x|", 1234));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 43 => \033[0m|%#9.2x|", 1234));
	printf("{%d}\n", printf("\033[1;32mTest 24 => \033[0m|%#-9.5o|", 42));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 24 => \033[0m|%#-9.5o|", 42));
	printf("{%d}\n", printf("\033[1;32mTest 5 => \033[0m|%#.o|", 0));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 5 => \033[0m|%#.o|", 0));
	printf("{%d}\n", printf("\033[1;32mTest own => \033[0m|%.o|", 0));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest own => \033[0m|%.o|", 0));
	return (0);
}
