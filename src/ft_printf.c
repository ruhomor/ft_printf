/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 12:50:14 by kachiote          #+#    #+#             */
/*   Updated: 2020/07/02 12:50:19 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//void	ft_sp_d(t_prnt info)
//{
//	ft_putnbr(va_arg(*(info.lst), int));
//}

void	ft_sp_d(t_prnt info)
{
    int     num;
    char    *numstr;
    int     numlen;
    char    *str;
    char    *buf;

    num = va_arg(*(info.lst), int);
    numstr = ft_itoa(num);  //  allocs num
    numlen = ft_strlen(numstr);
    if (info.min_width > numlen + 1 * (info.sign_char != 0))
    {
        str = ft_strnew(info.min_width - numlen);  //  allocs str
        buf = str;
    }
    numlen = info.min_width - numlen - 1 * (info.sign_char != 0);
    if (info.sign_char)  // TODO remake to work with left alignment
        *buf++ = info.sign_char;
    while (numlen--)  // TODO remake to work with left alignment
        *buf++ = info.pad;
    printf("|min_width-: %d| |left-: %d|", info.min_width, info.left);
    if (info.left)
    {
        ft_putstr(numstr);
        free(numstr);  //  frees num
        ft_putstr(str);
        free(str);  //  frees str
    }
    else
    {
        ft_putstr(str);
        free(str);  //  frees str
        ft_putstr(numstr);
        free(numstr);  //  frees num
    }
}

void	ft_sp_u(t_prnt info)
{
	ft_putunbr(va_arg(*(info.lst), unsigned int));
}

void	ft_sp_o(t_prnt info)
{
	ft_putstr(ft_itoa_base(va_arg(*(info.lst), unsigned int), 8)); //TODO TEST
}

void	ft_sp_x(t_prnt info)
{
	ft_putstr(ft_itoa_base(va_arg(*(info.lst), unsigned int), 16)); //TODO TEST
}

void	ft_sp_X(t_prnt info)
{
	ft_putstr(ft_strmap(ft_itoa_base(va_arg(*(info.lst), unsigned int), 16), ft_toupper)); //TODO TEST
}

void	ft_sp_c(t_prnt info)
{
	ft_putchar(va_arg(*(info.lst), int));
}

void	ft_sp_perc(void)
{
	ft_putchar('%');
}
/*
void	ft_sp_f(t_prnt info)
{
	ft_putstr(ft_ldtoa(va_arg(*(info.lst), unsigned int))); //TODO TEST
}

void	ft_sp_F(t_prnt info)
{
	ft_putstr(ft_strmap(ft_ldtoa(va_arg(*(info.lst), unsigned int)), ft_toupper)); //TODO TEST
}
*/
void	ft_printarg(t_prnt info)
{
	void		(*parg[8]) ();
	const char	*blabs = "diouxXc%";//fF";

	parg[0] = ft_sp_d;
	parg[1] = ft_sp_d;
	parg[2] = ft_sp_o;
	parg[3] = ft_sp_u;
	parg[4] = ft_sp_x;
	parg[5] = ft_sp_X;
	parg[6] = ft_sp_c;
	parg[7] = ft_sp_perc;
//	parg[8] = ft_sp_f;
//	parg[9] = ft_sp_F;
	parg[ft_strchr(blabs, info.type) - blabs](info);
}

void    ft_prnt_init(t_prnt *info)
{
    info->sign_char = '\0';
    info->min_width = 0;
    info->pad = ' ';
    info->alt_form = 0;
    info->left = 0;
    info->length = 0;
    info->pad_zero = 0;
    info->precision = -1;
    info->prefix = '\0';
    info->type = 0;
}

void	ft_printf(char *c, ...)
{
	va_list	lst;
	t_prnt	info;
	char    *tmp;

	va_start(lst, c);
	info.lst = &lst;
	ft_prnt_init(&info);
	while (*c != '\0')
	{
		info.type = *(c + 1); //TODO make this less stupid
		if (*c != '%')
			ft_putchar(*c);
		else
		{
			c++;
			ft_flag(info, &c);
			ft_prnt_init(&info);
		}
		c++;
	}
	va_end(lst);
}
