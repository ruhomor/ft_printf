/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 00:06:56 by sslift            #+#    #+#             */
/*   Updated: 2020/09/18 00:06:56 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*read_arg_u(t_prnt info, char *sign_char, char **numstr)
{
	if (info.size == 1)
		*numstr = ft_strnbr(info, (unsigned short int)
				va_arg(*(info.lst), unsigned int), sign_char);
	else if (info.size == 2)
		*numstr = ft_strnbr(info, (unsigned char)
				va_arg(*(info.lst), unsigned int), sign_char);
	else if (info.size == 3)
		*numstr = ft_strnbr(info,
							va_arg(*(info.lst), unsigned long int), sign_char);
	else if (info.size == 4)
		*numstr = ft_strnbr(info,
							va_arg(*(info.lst), unsigned long long int), sign_char);
	else
	*numstr = ft_strnbr(info, va_arg(*(info.lst), unsigned int), sign_char);
}

char		*read_arg_not_u(t_prnt info, char *sign_char, char **numstr)
{
	if (info.size == 1)
		*numstr = ft_strnbr(info, (short int)
				va_arg(*(info.lst), int), sign_char);
	else if (info.size == 2)
		*numstr = ft_strnbr(info, (char)
				va_arg(*(info.lst), int), sign_char);
	else if (info.size == 3)
		*numstr = ft_strnbr(info,
							va_arg(*(info.lst), long int), sign_char);
	else if (info.size == 4)
		*numstr = ft_strnbr(info,
							va_arg(*(info.lst), long long int), sign_char);
	else
	*numstr = ft_strnbr(info,
						va_arg(*(info.lst), int), sign_char);
}

void		read_arg(t_prnt info, char *sign_char, char **numstr)
{
	if (info.type == 'p')
		*numstr = ft_strnbr(info, (unsigned long long int)
				va_arg(*(info.lst), void*), sign_char);
	else
	{
		if (info.type == 'u')
			read_arg_u(info, sign_char, numstr);
		else if (info.type == '%')
		{
			info.type = 'c';
			*numstr = ft_strnbr(info, '%', sign_char);
		}
		else
			read_arg_not_u(info, sign_char, numstr);
	}
}
