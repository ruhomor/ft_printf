/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doxc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 00:14:00 by sslift            #+#    #+#             */
/*   Updated: 2020/09/18 00:14:00 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_sp_doxc_zero_prec_zero_doxc(t_prnt info,
											   char **numstr)
{
	if ((ft_ifin(info.type, "di") && (info.sign_char == '+')))
		**numstr = '+';
	else
	{
		free(*numstr);
		*numstr = ft_strnew(0);
	}
}

void			ft_sp_doxc_zero_prec_zero(t_prnt info,
										  char **numstr)
{
	info.pad = ' ';
	if (ft_ifin(info.type, "diuxXp"))
		ft_sp_doxc_zero_prec_zero_doxc(info, numstr);
	else if (info.type == 'o')
	{
		if (info.alt_form == 0)
		{
			free(*numstr);
			*numstr = ft_strnew(0);
		}
	}
	if (info.type == 'p')
		ft_numstart(info, numstr);
}

int			ft_sp_doxc_zero_prec_not_zero_neg(t_prnt info, char **numstr,
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
	{
		if (!(ft_ifin(info.type, "xX")))
			ft_numstart(info, numstr);
	}
	return (ft_printout(info, str, numstr));
}

int			ft_sp_doxc_zero_prec_not_zero(t_prnt info, char **numstr,
											 char **str, int *numlen)
{
	if (info.precision >= 0)
	{
		info.pad = ' ';
		*numlen = ft_strlen(*numstr);
		if (info.type == 'c' && !ft_strcmp(*numstr, "\0"))
			*numlen += 1;
		if (info.precision > *numlen)
			ft_gluezeros(info.precision - *numlen, numstr);
		if (!(ft_ifin(info.type, "xX")))
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
	else
		return (ft_sp_doxc_zero_prec_not_zero_neg(info, numstr, str, numlen));
}

int			ft_sp_doxc_zero(t_prnt info, char **numstr, char **str)
{
	int		numlen;

	if (info.precision == 0)
		ft_sp_doxc_zero_prec_zero(info, numstr);
	else
		return (ft_sp_doxc_zero_prec_not_zero(info, numstr, str, &numlen));
	if (*str)
		free(*str);
	ft_pudding(info, *numstr, str);
	return (ft_printout(info, str, numstr));
}
