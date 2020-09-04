#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("original: emem %-07.6s meme\n", "(null)");
	ft_printf("myprintf: emem %-07.6s meme\n", "(null)");
	return (0);
}
