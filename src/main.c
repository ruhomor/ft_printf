#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("emem %010.4d meme\n", -10);
	ft_printf("emem %010.4d meme\n", -10);
	return (0);
}
