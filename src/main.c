#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("original: emem %#02o meme\n", 2);
	ft_printf("myprintf: emem %#02o meme\n", 2);
	printf("original: emem %#2o meme\n", 3);
	ft_printf("myprintf: emem %#2o meme\n", 3);
	return (0);
}
