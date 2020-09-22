/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:02:20 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/17 23:36:26 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_reqsize(int n)
{
	int		res;

	if (n == 0)
		return (1);
	res = 0;
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	int				rsize;
	unsigned int	un;
	short int		sign;
	char			*res;

	sign = 0;
	if (n < 0)
	{
		sign = 1;
		un = -n;
	}
	else
		un = n;
	rsize = ft_reqsize(n) + sign;
	if (!(res = ft_strnew(rsize)))
		return (NULL);
	res[rsize] = '\0';
	if (sign == 1)
		*res = '-';
	ft_writenbr(res, un, rsize);
	return (res);
}
