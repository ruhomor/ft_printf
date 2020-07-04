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

void	ft_sp_d(va_list *lst)
{
	ft_putnbr(va_arg(*lst, int));
}

void	ft_sp_u(va_list *lst)
{
	ft_putunbr(va_arg(*lst, unsigned int));
}

void	ft_sp_o(va_list *lst)
{
	ft_putstr(ft_itoa_base(va_arg(*lst, unsigned int), 8)); //TODO TEST
}

void	ft_sp_x(va_list *lst)
{
	ft_putstr(ft_itoa_base(va_arg(*lst, unsigned int), 16)); //TODO TEST
}

void	ft_sp_X(va_list *lst)
{
	ft_putstr(ft_strmap(ft_itoa_base(va_arg(*lst, unsigned int), 16), ft_toupper)); //TODO TEST
}

void	ft_sp_c(va_list *lst)
{
	ft_putchar(va_arg(*lst, int));
}

void	ft_sp_perc(void)
{
	ft_putchar('%');
}
/*
void	ft_sp_f(va_list *lst)
{
	ft_putstr(ft_ldtoa(va_arg(*lst, unsigned int))); //TODO TEST
}

void	ft_sp_F(va_list *lst)
{
	ft_putstr(ft_strmap(ft_ldtoa(va_arg(*lst, unsigned int)), ft_toupper)); //TODO TEST
}
*/
void	ft_printarg(va_list *lst, char type)
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
	parg[ft_strchr(blabs, type) - blabs](lst);
}

void	ft_printf(char *c, ...)
{
	va_list	lst;

	va_start(lst, c);
	while (*c != '\0')
	{
		if (*c != '%')
			ft_putchar(*c);
		else
			ft_printarg(&lst, *++c);
		c++;
	}
	va_end(lst);
}
