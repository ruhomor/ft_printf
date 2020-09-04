#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("original: emem %+d meme\n", 76);
	ft_printf("myprintf: emem %+d meme\n", 76);
	return (0);
}
