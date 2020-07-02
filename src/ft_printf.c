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

#include <stdarg.h>
#include "libft/libft.h"

void	ft_printf(char *c, ...)
{
	char	*s;
	va_list	lst;

	va_start(lst, c);
	while (*c != '\0')
	{
		if (*c != '%')
		{
			ft_putchar(*c);
			c++;
			continue;
		}
		c++;
		if (*c == '\0')
		{
			break ;
		}
		handle //handle arg types_function
		c++;
	}
	va_end(lst);
}
