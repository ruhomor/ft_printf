#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
//	printf("{%d}\n", printf("\033[1;32mStd => \033[0m|%#05x|", 42));
//	ft_printf("{%d}\n", ft_printf("\033[1;31mOur => \033[0m|%#05x|", 42));
//	printf("{%d}\n", printf("\033[1;32mStd => \033[0m|%#0.5x|", 42));
//	ft_printf("{%d}\n", ft_printf("\033[1;31mOur => \033[0m|%#0.5x|", 42));
//	printf("std: %03.2d\n", -1);
//	ft_printf("our: %03.2d\n", -1);
//	printf("std: %+03.2d\n", 1);
//	ft_printf("our: %+03.2d\n", 1);
//	printf("std: %0+5d\n", 42);
//	ft_printf("our: %0+5d\n", 42);
//	printf("std: % d\n", -42);
//	ft_printf("our: % d\n", -42);
//	printf("std: % +d\n", 42);
//	ft_printf("our: % +d\n", 42);
//	printf("std: %0+5d\n", 42);
//	ft_printf("our: %0+5d\n", 42);
//	printf("std: %03.2d\n", 1);
//	ft_printf("our: %03.2d\n", 1);
//
//	printf("std: %05.3d\n", -1);
//    ft_printf("our: %05.3d\n", -1);
//	printf("std: %05d\n", -555);
//    ft_printf("our: %05d\n", -555);
    printf("std: %07d\n", -555);
    ft_printf("our: %07d\n", -555);
    printf("std: %04.4d\n", -555);
    ft_printf("our: %04.4d\n", -555);
    printf("std: %07.4d\n", -555);
    ft_printf("our: %07.4d\n", -555);
    printf("std: %+05.2x\n", 1);
	ft_printf("our: %+05.2x\n", 1);
    printf("std: %+07.7x\n", 1);
    ft_printf("our: %+07.7x\n", 1);
    printf("std: %#07.7x\n", 3228);
    ft_printf("our: %#07.7x\n", 3228);
    printf("std: %#07.7x\n", 3228);
    ft_printf("our: %#07.7x\n", 3228);
    printf("std: %#08.7o\n", 3228);
    ft_printf("our: %#08.7o\n", 3228);
    printf("std: %#06.7o\n", 3228);
	ft_printf("our: %#06.7o\n", 3228);
	return (0);

}
