#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("emem %15.10u meme\n", 1000009900);
	ft_printf("emem %15.10u meme\n", 1000009900);
	return (0);
}
