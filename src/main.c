#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("original: emem %.u meme\n", 0);
	ft_printf("myprintf: emem %.u meme\n", 0);
	printf("original: emem %#4o meme\n", 3);
	ft_printf("myprintf: emem %#4o meme\n", 3);
	return (0);
}
