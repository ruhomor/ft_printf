/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:31:50 by sslift            #+#    #+#             */
/*   Updated: 2020/09/05 21:26:58 by sslift           ###   ########.fr       */
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

int 	ft_size(t_prnt info, char **c)
{
	int size;

	size = -1; //default==-1
    while (ft_ifin(**c, "hlL"))
    {
    	if (**c == 'h')
		{
			(*c)++;
			if (**c == 'h')
			{
				size = 2; //hh==2
				(*c)++;
			}
			else
				size = 1; //h==1
		}
		else if (**c == 'l')
		{
			(*c)++;
			if (**c == 'l')
			{
				size = 4; //ll==4
				(*c)++;
			}
			else
				size = 3; //l==3
		}
		else if (**c == 'L')
		{
			(*c)++;
			size = 5; //L==5
		}
    }
    info.size = size;
    return (ft_conversion(info, c));
}

int 	ft_precision(t_prnt info, char **c)
{
    int precision;

    precision = -1;
    if (**c == '.')
    {
        precision = 0;
        (*c)++;
    }
    while (ft_ifin(**c, "1234567890"))
    {
        precision *= 10;
        precision += **c - '0';
        (*c)++;
    }
    info.precision = precision;
    return (ft_size(info, c));
}

int 	ft_width(t_prnt info, char **c)
{
    int width;

    width = 0;
    while (ft_ifin(**c, "1234567890"))
    {
        width *= 10;
        width += **c - '0';
        (*c)++;
    }
    info.min_width = width;
    return (ft_precision(info, c));
}

int 	ft_flag(t_prnt info, char **c)
{
	while (ft_ifin(**c, "#+-0 "))
	{
		if (**c == '-')
			info.left = TRUE;
		else if (**c == '0')
			info.pad = '0';
		else if (**c == '#')
			info.alt_form = TRUE;
		else if (**c == '+')
			info.sign_char = '+';
		else if (**c == ' ')
			if (!info.sign_char)
				info.sign_char = ' ';
        (*c)++;
	}
	return (ft_width(info, c));
}

