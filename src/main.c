#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("original: emem %06d meme\n", -35);
	ft_printf("myprintf: emem %06d meme\n", -35);
	return (0);
}
