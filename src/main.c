#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("original: emem %-2.1f meme\n", 98.76);
	ft_printf("myprintf: emem %-2.1f meme\n", 98.76);
	return (0);
}
