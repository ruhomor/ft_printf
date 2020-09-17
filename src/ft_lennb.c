/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lennb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 23:38:22 by sslift            #+#    #+#             */
/*   Updated: 2020/09/17 23:40:46 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lennbl(unsigned long long int nb, char base)
{
	int len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}

int	ft_lennbh(unsigned short int nb, char base)
{
	int len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}

int	ft_lennbhh(unsigned char nb, char base)
{
	int len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}
