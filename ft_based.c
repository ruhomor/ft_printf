/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_based.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 00:01:14 by sslift            #+#    #+#             */
/*   Updated: 2020/09/18 00:01:14 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_based_o(t_prnt info, long long int num)
{
	if (info.size == 1)
		return (ft_itoa_baseh(num, 8));
	else if (info.size == 2)
		return (ft_itoa_basehh(num, 8));
	else if (info.size == -1)
		return (ft_itoa_base(num, 8));
	else
		return (ft_itoa_basel(num, 8));
}

char		*ft_based_xp(t_prnt info, long long int num)
{
	if (info.size == 1)
		return (ft_itoa_baseh(num, 16));
	else if (info.size == 2)
		return (ft_itoa_basehh(num, 16));
	else if (info.size == -1)
		return (ft_itoa_base(num, 16));
	else
		return (ft_itoa_basel(num, 16));
}

char		*ft_based(t_prnt info, long long int num)
{
	char	*buf;
	char	*numstr;

	if (info.type == 'o')
		return (ft_based_o(info, num));
	else if (ft_ifin(info.type, "xp"))
		return (ft_based_xp(info, num));
	else if (info.type == 'X')
	{
		if (info.size == 1)
			buf = ft_itoa_baseh(num, 16);
		else if (info.size == 2)
			buf = ft_itoa_basehh(num, 16);
		else if (info.size == -1)
			buf = ft_itoa_base(num, 16);
		else
			buf = ft_itoa_basel(num, 16);
		numstr = ft_strmap(buf, ft_toupperchar);
		free(buf);
		return (numstr);
	}
	else if (info.type == 'u')
		return (ft_itoa_basel(num, 10));
	return (0);
}
