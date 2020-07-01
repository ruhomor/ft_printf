/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:53:05 by kachiote          #+#    #+#             */
/*   Updated: 2019/09/15 17:15:31 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *buf;

	buf = dst;
	while ((*src) && (len))
	{
		*dst = *src++;
		dst++;
		len--;
	}
	while (len--)
		*dst++ = '\0';
	return (buf);
}
