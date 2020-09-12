/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 19:49:42 by sslift            #+#    #+#             */
/*   Updated: 2020/09/09 23:37:10 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(t_prnt info, char **c)
{
	info.type = **c;
	if (info.type == 'p')
	{
		info.type = 'x';
		info.alt_form = 1;
		info.size = 4;
	}
	if ((ft_ifin(info.type, "ouxXc%") && (info.sign_char == ' ')))
		info.sign_char = '\0';
	return (ft_printarg(info));
}
