#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{

	printf("original: emem %0.10hhx meme\n", 98123456);
	ft_printf("myprintf: emem %0.10hhx meme\n", 98123456);
	printf("original: emem %ho meme\n", -12342283221488);
	ft_printf("myprintf: emem %ho meme\n", -12342283221488);
	return (0);
}
