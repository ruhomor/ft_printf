/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:31:50 by sslift            #+#    #+#             */
/*   Updated: 2020/09/22 11:49:24 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sizehh(t_prnt info, char **c, int *size)
{
	(*c)++;
	if (**c == 'h')
	{
		*size = 2;
		(*c)++;
	}
	else
		*size = 1;
}

int		ft_size(t_prnt info, char **c)
{
	int size;

	size = -1;
	if (**c == 'h')
		ft_sizehh(info, c, &size);
	else if (**c == 'l')
	{
		(*c)++;
		if (**c == 'l')
		{
			size = 4;
			(*c)++;
		}
		else
			size = 3;
	}
	else if (**c == 'L')
	{
		(*c)++;
		size = 5;
	}
	info.size = size;
	return (ft_conversion(info, c));
}

int		ft_precision(t_prnt info, char **c)
{
	int precision;

	precision = -1;
	if (**c == '.')
	{
		precision = 0;
		(*c)++;
	}
	if (**c == '*')
	{
		precision = va_arg(*(info.lst), int);
		if (precision < 0)
			precision = -1;
		(*c)++;
		if (ft_ifin(**c, "1234567890"))
			precision = 0;
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

int		ft_width(t_prnt info, char **c)
{
	int width;

	width = 0;
	if (**c == '*')
	{
		width = va_arg(*(info.lst), int);
		if (width < 0)
		{
			info.left = TRUE;
			width = -width;
		}
		(*c)++;
		if (ft_ifin(**c, "1234567890"))
			width = 0;
	}
	while (ft_ifin(**c, "1234567890"))
	{
		width *= 10;
		width += **c - '0';
		(*c)++;
	}
	info.min_width = width;
	return (ft_precision(info, c));
}

int		ft_flag(t_prnt info, char **c)
{
	if (**c == '\0')
	{
		info.lst++;
		return (0);
	}
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
