/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printout_cond.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 00:09:04 by sslift            #+#    #+#             */
/*   Updated: 2020/09/18 00:09:04 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_pudding(t_prnt info, char *numstr, char **str)
{
	int	numlen;

	numlen = ft_strlen(numstr);
	if (info.type == 'c' && !ft_strcmp(numstr, "\0"))
		numlen += 1;
	if (info.min_width > numlen)
	{
		*str = ft_strnew(info.min_width - numlen);
		ft_memset(*str, info.pad, info.min_width - numlen);
	}
	else
		*str = ft_strnew(0);
}

int			ft_printout_left(t_prnt info, char **str, char **numstr)
{
	if (info.type == 'c' && !ft_strcmp(*numstr, "\0"))
	{
		ft_putchar(0);
		info.len += 1;
	}
	ft_putstr(*numstr);
	if (*str)
	{
		ft_putstr(*str);
		info.len += ft_strlen(*str);
		free(*str);
	}
	return (info.len);
}

int			ft_printout(t_prnt info, char **str, char **numstr)
{
	if (info.left == 1)
		info.len += ft_printout_left(info, str, numstr);
	else
	{
		if (*str)
		{
			ft_putstr(*str);
			info.len += ft_strlen(*str);
			free(*str);
		}
		if (info.type == 'c' && !ft_strcmp(*numstr, "\0"))
		{
			ft_putchar(0);
			info.len += 1;
		}
		ft_putstr(*numstr);
	}
	info.len += ft_strlen(*numstr);
	free(*numstr);
	return (info.len);
}

void		ft_gluezeros(int zeros, char **numstr)
{
	char	*zerostring;
	char	*buf;

	zerostring = ft_strzeros(zeros);
	buf = *numstr;
	*numstr = ft_strjoin(zerostring, *numstr);
	free(buf);
	free(zerostring);
}

int			ft_formcounter(t_prnt info, char *numstr)
{
	if (ft_ifin(info.type, "di"))
	{
		if (info.sign_char)
			return (1);
	}
	if (ft_ifin(info.type, "xXp"))
	{
		if (info.alt_form == 1)
			return (2);
	}
	if (info.type == 'o')
	{
		if (info.alt_form == 1)
		{
			if (*numstr != '0')
				return (1);
		}
	}
	return (0);
}
