/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:04:29 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/17 23:36:26 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	short int	sign;
	int			res;

	res = 0;
	sign = -1;
	while ((*str) && ((ft_isspace(*str))) && (*str != '-') && (*str != '+'))
		str++;
	if (*str == '-')
	{
		sign = 1;
		str++;
	}
	else
	{
		if (*str == '+')
		{
			sign = -1;
			str++;
		}
	}
	while ((*str) && ft_isdigit(*str))
		res = res * 10 - (*str++ - '0');
	return ((int)(res * sign));
}
