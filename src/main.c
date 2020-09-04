#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("original: emem %-10.1s meme\n", "abc");
	ft_printf("myprintf: emem %-10.1s meme\n", "abc");
	return (0);
}
