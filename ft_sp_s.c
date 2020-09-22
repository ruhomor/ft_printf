/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 00:19:51 by sslift            #+#    #+#             */
/*   Updated: 2020/09/18 00:19:51 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_sp_s_printout(t_prnt info, char **numstr, char **str, int clear)
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
	if (clear)
		free(*numstr);
	return (info.len);
}

void		ft_sp_s_meme(t_prnt info, char **numstr, int *numlen)
{
	char *buf;

	ft_strncpy(buf = ft_strnew(info.precision), *numstr, info.precision);
	*numstr = buf;
	*numlen = info.precision;
}

int			ft_sp_s(t_prnt info)
{
	char	*numstr;
	int		numlen;
	char	*str;
	int		clear;

	str = 0;
	clear = FALSE;
	if ((info.left == 1) && (info.pad == '0'))
		info.pad = ' ';
	numstr = va_arg(*(info.lst), char *);
	if (!(numstr))
	{
		numstr = ft_strdup("(null)");
		clear = TRUE;
	}
	numlen = ft_strlen(numstr);
	if ((info.precision != -1) && (numlen > info.precision))
		ft_sp_s_meme(info, &numstr, &numlen);
	if (numlen < info.min_width)
	{
		str = ft_strnew(info.min_width - numlen);
		ft_memset(str, info.pad, info.min_width - numlen);
	}
	return (ft_sp_s_printout(info, &numstr, &str, clear));
}
