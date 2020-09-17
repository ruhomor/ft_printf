/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numstart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 00:11:50 by sslift            #+#    #+#             */
/*   Updated: 2020/09/18 00:11:50 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_numstart_di(t_prnt info, char **numstr, char **sign)
{
	char	*buf;

	if (info.sign_char)
	{
		*sign = ft_strnew(1);
		**sign = info.sign_char;
		buf = *numstr;
		*numstr = ft_strjoin(*sign, *numstr);
		free(buf);
		free(*sign);
	}
}

void		ft_numstart_xxp(t_prnt info, char **numstr, char **sign)
{
	char	*buf;

	if (info.alt_form == 1)
	{
		if (ft_ifin(info.type, "xp"))
			*sign = ft_strdup("0x");
		else
			*sign = ft_strdup("0X");
		buf = *numstr;
		*numstr = ft_strjoin(*sign, *numstr);
		free(buf);
		free(*sign);
	}
}

void		ft_numstart(t_prnt info, char **numstr)
{
	char *buf;
	char *sign;

	if (ft_ifin(info.type, "di"))
		ft_numstart_di(info, numstr, &sign);
	if (ft_ifin(info.type, "xXp"))
		ft_numstart_xxp(info, numstr, &sign);
	if (info.type == 'o')
	{
		if (info.alt_form == 1)
		{
			if (**numstr != '0')
			{
				sign = ft_strnew(1);
				*sign = '0';
				buf = *numstr;
				*numstr = ft_strjoin(sign, *numstr);
				free(buf);
				free(sign);
			}
		}
	}
}
