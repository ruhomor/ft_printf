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

void	ft_printarg(va_list *lst, char type)
{
	if (type == 'c')
		ft_putchar(va_arg(*lst, char));
	if (type == 'd')
		ft_putnbr(va_arg(*lst, int));
}

void	ft_printf(char *c, ...)
{
	va_list	lst;

	va_start(lst, c);
	while (*c)
	{
		while (*c != '%')
			ft_putchar(*c++);
		c++;
		ft_printarg(&lst, *c);
	}
	va_end(lst);
}
