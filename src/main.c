#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("original: emem %5c meme\n", '\0');
	ft_printf("myprintf: emem %5c meme\n", '\0');
	return (0);
}
