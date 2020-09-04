#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("original: emem % +5.2d meme\n", 9);
	ft_printf("myprintf: emem % +5.2d meme\n", 9);
	return (0);
}
