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
	ft_putunbr(va_arg(*lst, unsigned int)); //TODO
}

void	ft_sp_c(va_list *lst)
{
	ft_putchar(va_arg(*lst, int));
}

void	ft_printarg(va_list *lst, char type)
{
	if ((type == 'd') || (type == 'i'))
		ft_sp_d(lst);
	if (type == 'u')
		ft_sp_u(lst);
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
