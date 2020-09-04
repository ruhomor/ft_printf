#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("emem %38.22u meme\n", -10);
	ft_printf("emem %38.22u meme\n", -10);
	return (0);
}
