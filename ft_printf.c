/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 12:50:14 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/18 00:21:11 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printarg(t_prnt info)
{
	int			(*parg[12])();
	const char	*blabs = "diouxXc%fFsp";

	if (!ft_ifin(info.type, blabs))
	{
		ft_putchar(info.type);
		return (1);
	}
	parg[0] = ft_sp_doxc_new;
	parg[1] = ft_sp_doxc_new;
	parg[2] = ft_sp_doxc_new;
	parg[3] = ft_sp_doxc_new;
	parg[4] = ft_sp_doxc_new;
	parg[5] = ft_sp_doxc_new;
	parg[6] = ft_sp_doxc_new;
	parg[7] = ft_sp_doxc_new;
	parg[8] = ft_sp_f;
	parg[9] = ft_sp_f;
	parg[10] = ft_sp_s;
	parg[11] = ft_sp_doxc_new;
	return (parg[ft_strchr(blabs, info.type) - blabs](info));
}

void		ft_prnt_init(t_prnt *info)
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
	info->len = 0;
	info->type = 0;
}

int			ft_printf(char *c, ...)
{
	va_list	lst;
	t_prnt	info;
	int		res;

	res = 0;
	va_start(lst, c);
	info.lst = &lst;
	ft_prnt_init(&info);
	while (*c != '\0')
	{
		if (*c != '%')
		{
			ft_putchar(*c);
			res++;
		}
		else
		{
			c++;
			res += ft_flag(info, &c);
		}
		if (*c != '\0')
			c++;
	}
	va_end(lst);
	return (res);
}
