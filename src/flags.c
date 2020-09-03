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
    //TODO make it in future

    while (ft_ifin(*c, "hl"))
    {
        c++;
    }
    ft_conversion(info, c);
}

void 	ft_precision(t_prnt info, char *c)
{
    int precision;

    precision = -1;
    if (*c == '.')
    {
        precision = 0;
        c++;
    }
    while (ft_ifin(*c, "1234567890"))
    {
        precision *= 10;
        precision += *c - '0';
        c++;
    }
    info.precision = precision;
    ft_size(info, c);
}

void 	ft_width(t_prnt info, char *c)
{
    int width;

    width = 0;
    while (ft_ifin(*c, "1234567890"))
    {
        width *= 10;
        width += *c - '0';
        c++;
    }
    info.min_width = width;
    ft_precision(info, c);
}

void 	ft_flag(t_prnt info, char *c)
{
    info.pad = ' '; // TODO check if thats ok???
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

