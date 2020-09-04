#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{

	printf("original: emem %#X meme\n", 0);
	ft_printf("myprintf: emem %#X meme\n", 0);
	printf("original: emem %#x meme\n", 0);
	ft_printf("myprintf: emem %#x meme\n", 0);
	printf("original: emem %#o meme\n", 0);
	ft_printf("myprintf: emem %#o meme\n\n\n", 0);
	printf("original: emem %#.o meme\n", 0);
	ft_printf("myprintf: emem %#.o meme\n", 0);
	printf("original: emem %.o meme\n", 0);
	ft_printf("myprintf: emem %.o meme\n", 0);
	return (0);
}
