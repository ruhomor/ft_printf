/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:22:05 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/17 23:36:27 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nbrlen(unsigned int n)
{
	int		len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static	int		ft_pow10(int len)
{
	int		res;

	res = 1;
	while (len--)
		res *= 10;
	return (res);
}

void			ft_putunbr_fd(unsigned int n, int fd)
{
	int		len;
	int		divisor;

	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		len = ft_nbrlen(n) - 1;
		while (n)
		{
			divisor = ft_pow10(len--);
			ft_putchar_fd(n / divisor + '0', fd);
			n %= divisor;
		}
		len++;
		while (len--)
			ft_putchar_fd('0', fd);
	}
}
