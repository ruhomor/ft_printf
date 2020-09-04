#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("emem %#22X meme\n", -10);
	ft_printf("emem %#22X meme\n", -10);
	return (0);
}
