#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	printf("meme%u\n", 4294967297);
	ft_printf("meme%u", 4294967297);
	return (0);
}
