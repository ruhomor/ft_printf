#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("original: emem %#o meme\n", 0);
	ft_printf("myprintf: emem %#o meme\n", 0);
	printf("original: emem %#.o meme\n", 0);
	ft_printf("myprintf: emem %#.o meme\n", 0);
	printf("original: emem %.o meme\n", 0);
	ft_printf("myprintf: emem %.o meme\n", 0);
	return (0);
}
