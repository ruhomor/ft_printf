/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrmod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 00:04:34 by sslift            #+#    #+#             */
/*   Updated: 2020/09/18 00:04:34 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		ft_toupperchar(char c)
{
	if (ft_islowercase(c))
		return (c - 32);
	return (c);
}

char		*ft_chars(t_prnt info, int num)
{
	char *numstr;

	numstr = ft_strnew(1 * sizeof(char));
	*numstr = (char)num;
	return (numstr);
}

void		ft_writenbrl(char *s, unsigned long long int n, int size)
{
	char	*buf;

	if (n == 0)
		*s = '0';
	buf = s + size - 1;
	while (n)
	{
		*buf = (n % 10) + '0';
		n /= 10;
		buf--;
	}
}

char		*ft_strnbr(t_prnt info, long long int num, char *sign_char)
{
	if (ft_ifin(info.type, "id"))
		return (ft_itoal(num, sign_char));
	else
	{
		if (ft_ifin(info.type, "ouxXp"))
			return (ft_based(info, num));
		else if (info.type == 'c')
			return (ft_chars(info, num));
	}
}
