/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 22:29:11 by kachiote          #+#    #+#             */
/*   Updated: 2019/09/24 14:31:40 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static	int		ft_nbrlen(int n)
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

void			ft_putnbr_fd(int n, int fd)
{
	int		len;
	int		divisor;

	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		if (n < 0)
			ft_putchar_fd('-', fd);
		len = ft_nbrlen(n) - 1;
		while (n)
		{
			divisor = ft_pow10(len--);
			ft_putchar_fd(ft_absolute(n / divisor) + '0', fd);
			n %= divisor;
		}
		len++;
		while (len--)
			ft_putchar_fd('0', fd);
	}
}
