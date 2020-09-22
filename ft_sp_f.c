/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 00:21:43 by sslift            #+#    #+#             */
/*   Updated: 2020/09/18 00:21:43 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_sp_f_printout(t_prnt info, char **numstr, char **str)
{
	if (info.left == 1)
	{
		ft_putstr(*numstr);
		if (*str)
		{
			ft_putstr(*str);
			info.len += ft_strlen(*str);
			free(*str);
		}
	}
	else
	{
		if (*str)
		{
			ft_putstr(*str);
			info.len += ft_strlen(*str);
			free(*str);
		}
		ft_putstr(*numstr);
	}
	info.len += ft_strlen(*numstr);
	free(*numstr);
	return (info.len);
}

int			ft_sp_f(t_prnt info)
{
	char	*numstr;
	int		numlen;
	char	*str;

	str = NULL;
	if (info.size == 5)
		numstr = ft_ftoa(va_arg(*(info.lst), long double), info.precision);
	else
		numstr = ft_ftoa(va_arg(*(info.lst), double), info.precision);
	numlen = ft_strlen(numstr);
	if (numlen < info.min_width)
	{
		str = ft_strnew(info.min_width - numlen);
		ft_memset(str, info.pad, info.min_width - numlen);
	}
	return (ft_sp_f_printout(info, &numstr, &str));
}
