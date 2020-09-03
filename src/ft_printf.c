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
#include <stdio.h>  //  TODO REMOVE

char	ft_toupperchar(char c)
{
    if (ft_islowercase(c))
        return (c - 32);
    return (c);
}

size_t     ft_converse(t_prnt info, int num, char **numstr)
{
    char *buf;

    if (ft_ifin(info.type, "idu"))
        *numstr = ft_itoa(num);  //  allocs numstr
    else if (info.type == 'o')
        *numstr = ft_itoa_base(num, 8);
    else if (info.type == 'x')
        *numstr = ft_itoa_base(num, 16);
    else if (info.type == 'X')
    {
        *numstr = ft_strmap(buf = ft_itoa_base(num, 16), ft_toupperchar);
        free(buf);
    }
    return ft_strlen(*numstr) - ft_ifin(info.type, "id") * (num < 0);
}

char    *ft_precise(t_prnt info, int num) {
    char    *numstr;
    char    *buf;
    size_t  numlen;

    numlen = ft_converse(info, num, &numstr);
    if (info.precision > (numlen))
    {
        buf = numstr;
        numstr = ft_strjoin(ft_strzeros(info.precision - (numlen)), numstr + (num < 0) * ft_ifin(info.type, "id"));
        free(buf);
        if ((num < 0) * ft_ifin(info.type, "id") && (info.sign_char != '+'))
        {
            buf = numstr;
            numstr = ft_strjoin("-", numstr);
            free(buf);
        }
    }
    return numstr;
}

void    ft_print_pad(t_prnt info, char **str, char **numstr)
{
    if (info.left)
    {
        ft_putstr(*numstr);
        free(*numstr);  //  frees numstr
        if (*str)
        {
            ft_putstr(*str);
            free(*str);  //  frees str
        }
    }
    else
    {
        if (*str)
        {
            ft_putstr(*str);
            free(*str);  //  frees str
        }
        ft_putstr(*numstr);
        free(*numstr);  //  frees num
    }
}

void	ft_sp_dox(t_prnt info)
{
    char *numstr;
    int numlen;
    char *str;

    if (info.precision != -1)
        info.pad = ' ';
    str = NULL;
    if (info.type == 'u')
        numstr = ft_precise(info, va_arg(*(info.lst), unsigned int));
    else
        numstr = ft_precise(info, va_arg( *(info.lst), int));
    numlen = ft_strlen(numstr);
    if (info.min_width > numlen)
    {
        str = ft_strnew(info.min_width - numlen);
        ft_memset(str, info.pad, info.min_width - numlen);
    }
    ft_print_pad(info, &str, &numstr);
}

void	ft_sp_u(t_prnt info)
{
	ft_putunbr(va_arg(*(info.lst), unsigned int));
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

	parg[0] = ft_sp_dox;
	parg[1] = ft_sp_dox;
	parg[2] = ft_sp_dox;
	parg[3] = ft_sp_dox;
	parg[4] = ft_sp_dox;
	parg[5] = ft_sp_dox;
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
