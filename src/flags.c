/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:31:50 by sslift            #+#    #+#             */
/*   Updated: 2020/08/24 23:09:02 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_ifin(char c, const char *s)
{
	while (*s)
		if (c == *s++)
			return TRUE;
	return FALSE;
}

void 	ft_size(t_prnt info, char *c)
{

}

void 	ft_precision(t_prnt info, char *c)
{

}

void 	ft_width(t_prnt info, char *c)
{

}

void 	ft_flag(t_prnt info, char *c)
{
	while (ft_ifin(*c, "#+-0 "))
	{
		if (*c == '-')
			info.left = TRUE;
		else if (*c == '0')
			info.pad = '0';
		else if (*c == '#')
			info.alt_form = TRUE;
		else if (*c == '+')
			info.sign_char = '+';
		else if (*c == ' ')
			if (!info.sign_char)
				info.sign_char = ' ';
		c++;
	}

	ft_width(info, c);
}

