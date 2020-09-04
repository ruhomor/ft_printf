/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 12:50:14 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/04 19:07:57 by kachiote         ###   ########.fr       */
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

void       ft_handle_h(t_prnt info, char **numstr)
{
    char    *buf;

    if (info.type == 'o')
    {
        buf = *numstr;
        *numstr = ft_strjoin("0", *numstr);
        free(buf);
    }
    else if (info.type == 'x')
    {
        buf = *numstr;
        *numstr = ft_strjoin("0x", *numstr);
        free(buf);
    }
    else if (info.type == 'X')
    {
        buf = *numstr;
        *numstr = ft_strjoin("0X", *numstr);
        free(buf);
    }
}

void        ft_chars(t_prnt info, char **numstr, int num)
{
    *numstr = ft_strnew(1 * sizeof(char));
    **numstr = (char)num;
}

void        ft_based(t_prnt info, char **numstr, int num)
{
    char    *buf;

    if (info.type == 'o')
        *numstr = ft_itoa_base(num, 8);
    else if (info.type == 'x')
        *numstr = ft_itoa_base(num, 16);
    else if (info.type == 'X')
    {
        *numstr = ft_strmap(buf = ft_itoa_base(num, 16), ft_toupperchar);
        free(buf);
    }
    else if (info.type == 'u')
        *numstr = ft_itoa_base(num, 10);
}

size_t     ft_converse(t_prnt info, int num, char **numstr)
{
    char *buf;

    if (ft_ifin(info.type, "id"))
        *numstr = ft_itoa(num);  //  allocs numstr
    else if (ft_ifin(info.type, "ouxX"))
        ft_based(info, numstr, num);
    else if (info.type == 'c')
	{
        ft_chars(info, numstr, num);
		return 1;
	}
    if (info.alt_form == 1)
        ft_handle_h(info, numstr);
    return ft_strlen(*numstr) - ft_ifin(info.type, "id") * (num < 0)
    - (info.alt_form) * (2 * ft_ifin(info.type, "xX") + (info.type == 'o'));
}

void	ft_manageplus(t_prnt info, char **numstr, int num)
{
    char *buf;

	if ((num > 0) * ft_ifin(info.type, "id") && (info.sign_char == '+'))
	{
        buf = *numstr;
        *numstr = ft_strjoin("+", *numstr);
        free(buf);
	}
	if (info.sign_char == ' ')
	{
        buf = *numstr;
        *numstr = ft_strjoin(" ", *numstr);
        free(buf);
	}
}

void    ft_formnsign(t_prnt info, char **numstr, int num)
{
    char *buf;

    if ((num < 0) * ft_ifin(info.type, "id") && (info.sign_char != '+'))
    {
        buf = *numstr;
        *numstr = ft_strjoin("-", *numstr);
        free(buf);
	}
    if (info.alt_form == 1)
    {
        if (info.type == 'x')
        {
            buf = *numstr;
            *numstr = ft_strjoin("0x", *numstr);
            free(buf);
        }
        if (info.type == 'X')
        {
            buf = *numstr;
            *numstr = ft_strjoin("0X", *numstr);
            free(buf);
        }
        else if (info.type == 'o')
        {
            buf = *numstr;
            *numstr = ft_strjoin("0", *numstr);
            free(buf);
        }
    }
}

char    *ft_precise(t_prnt info, int num)
{
    char    *numstr;
    char    *buf;
    int     numlen;

    numlen = ft_converse(info, num, &numstr);
    if ((info.precision > (numlen)) && (!(info.type == 'c')))
    {
        buf = numstr;
        numstr = ft_strjoin(ft_strzeros(info.precision - (numlen)), numstr + (num < 0) * ft_ifin(info.type, "id") + (info.alt_form == 1) * (2 * (ft_ifin(info.type, "xX")) + (info.type == 'o')));
        free(buf);
        ft_formnsign(info, &numstr, num);
    }
	ft_manageplus(info, &numstr, num);
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

void	ft_sp_doxc(t_prnt info)
{
    char    *numstr;
    int     numlen;
    char    *str;

    if (info.precision != -1)
        info.pad = ' ';
    if ((info.left == 1) && (info.pad == '0')) //  ignore '0' if '-' is present
        info.pad = ' ';
    str = NULL;
    if (info.type == 'u')
        numstr = ft_precise(info, va_arg(*(info.lst), unsigned int));
    else if (info.type == '%')
	{
		info.type = 'c';
		numstr = ft_precise(info, '%');
	}
	else
        numstr = ft_precise(info, va_arg(*(info.lst), int));
    numlen = ft_strlen(numstr) + (info.type == 'c') * (*numstr == '\0');
    if (info.min_width > numlen)
    {
        str = ft_strnew(info.min_width - numlen);
        ft_memset(str, info.pad, info.min_width - numlen);
    }
    ft_print_pad(info, &str, &numstr);
}

void	ft_sp_perc(void)
{
	ft_putchar('%');
}

void    ft_sp_s(t_prnt info)
{
    char    *numstr;
    int     numlen;
    char    *str;
    char    *buf;
	int		clear;

    str = 0;
	clear = FALSE;
    //if (info.precision != -1)
    //    info.pad = ' ';
    if ((info.left == 1) && (info.pad == '0')) //  ignore '0' if '-' is present
        info.pad = ' ';
    numstr = va_arg(*(info.lst), char *);  //  does it allocs - MALLOCS??????
	if (!(numstr))
	{
		numstr = ft_strdup("(null)");
		clear = TRUE;
	}
    numlen = ft_strlen(numstr);
    if ((info.precision != -1) && (numlen > info.precision))
    {
        ft_strncpy(buf = ft_strnew(info.precision), numstr, info.precision);
        //free(numstr);
        numstr = buf;
        numlen = info.precision;
    }
    if (numlen < info.min_width)
    {
        str = ft_strnew(info.min_width - numlen);
        ft_memset(str, info.pad, info.min_width - numlen);
    }
    if (info.left == 1)
    {
        ft_putstr(numstr);
        if (str)
		{
            ft_putstr(str);
			free(str);
		}
    }
    else
    {
        if (str)
		{
            ft_putstr(str);
			free(str);
		}
        ft_putstr(numstr);
    }
	if (clear)
		free(numstr);
}

void	ft_sp_f(t_prnt info)
{
    char    *numstr;
    int     numlen;
    char    *str;
    char    *buf;

    str = NULL;
    numstr = ft_ftoa(va_arg(*(info.lst), double), info.precision);
    numlen = ft_strlen(numstr);
    if (numlen < info.min_width)
    {
        str = ft_strnew(info.min_width - numlen);
        ft_memset(str, info.pad, info.min_width - numlen);
    }
    if (info.left == 1)
    {
        ft_putstr(numstr);
        if (str)
            ft_putstr(str);
    }
    else
    {
        if (str)
            ft_putstr(str);
        ft_putstr(numstr);
    }
}

void	ft_printarg(t_prnt info)
{
	void		(*parg[11]) ();
	const char	*blabs = "diouxXc%fFs";//fF";

	parg[0] = ft_sp_doxc;
	parg[1] = ft_sp_doxc;
	parg[2] = ft_sp_doxc;
	parg[3] = ft_sp_doxc;
	parg[4] = ft_sp_doxc;
	parg[5] = ft_sp_doxc;
	parg[6] = ft_sp_doxc;
	parg[7] = ft_sp_doxc;
	parg[8] = ft_sp_f;
	parg[9] = ft_sp_f;
    parg[10] = ft_sp_s;
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
