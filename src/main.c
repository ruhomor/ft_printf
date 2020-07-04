#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("meme %o %x %X %c %% emem\n", 8, 15, 15, 'T');
	ft_printf("meme %o %x %X %c %% emem\n", 8, 15, 15, 'T');
	return (0);
}
