#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("original: emem %0-10s meme\n", "abc");
	ft_printf("myprintf: emem %0-10s meme\n", "abc");
	return (0);
}
