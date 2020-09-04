#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("original: emem %+.10d meme\n", -76);
	ft_printf("myprintf: emem %+.10d meme\n", -76);
	return (0);
}
