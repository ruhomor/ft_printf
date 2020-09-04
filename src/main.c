#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("original: emem |titi % +---.5c et%%%0004% et %+1%| meme\n", '8');
	ft_printf("myprintf: emem |titi % +---.5c et%%%0004% et %+1%| meme\n", '8');
	return (0);
}
