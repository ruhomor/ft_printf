/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doxc_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 00:17:45 by sslift            #+#    #+#             */
/*   Updated: 2020/09/18 00:17:45 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_sp_doxc_new_prec_pos(t_prnt info, char **numstr,
									   char **str, int *numlen)
{
	info.pad = ' ';
	*numlen = ft_strlen(*numstr);
	if (info.type == 'c' && !ft_strcmp(*numstr, "\0"))
		*numlen += 1;
	if ((info.precision > *numlen) && (info.type != 'c'))
		ft_gluezeros(info.precision - *numlen, numstr);
	ft_numstart(info, numstr);
	*numlen = ft_strlen(*numstr);
	if (info.type == 'c' && !ft_strcmp(*numstr, "\0"))
		*numlen += 1;
	if (info.min_width > *numlen)
	{
		if (*str)
			free(*str);
		ft_pudding(info, *numstr, str);
	}
	return (ft_printout(info, str, numstr));
}

int			ft_sp_doxc_new_prec_neg(t_prnt info, char **numstr,
									   char **str, int *numlen)
{
	*numlen = ft_strlen(*numstr);
	if (info.type == 'c' && !ft_strcmp(*numstr, "\0"))
		*numlen += 1;
	if (info.min_width > *numlen)
	{
		if (info.pad == '0')
			ft_gluezeros(info.min_width - *numlen -
						 ft_formcounter(info, *numstr), numstr);
		ft_numstart(info, numstr);
		if (info.pad == ' ')
		{
			if (*str)
				free(*str);
			ft_pudding(info, *numstr, str);
		}
	}
	else
		ft_numstart(info, numstr);
	return (ft_printout(info, str, numstr));
}

int			ft_sp_doxc_new(t_prnt info)
{
	char	*numstr;
	int		numlen;
	char	*str;

	str = ft_strnew(0);
	if ((info.left == 1) && (info.pad == '0'))
		info.pad = ' ';
	read_arg(info, &info.sign_char, &numstr);
	if (!(ft_strcmp("0", numstr)))
		return (ft_sp_doxc_zero(info, &numstr, &str));
	if (info.precision >= 0)
		return (ft_sp_doxc_new_prec_pos(info, &numstr, &str, &numlen));
	else
		return (ft_sp_doxc_new_prec_neg(info, &numstr, &str, &numlen));
}
