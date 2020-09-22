/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:02:20 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/17 23:36:27 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = 0;
	while ((*dst) && (size))
	{
		dst++;
		dstlen++;
		size--;
	}
	srclen = ft_strlen(src);
	while (*src && (size > 1))
	{
		*dst++ = *src++;
		size--;
	}
	if ((size == 1) || (!(*src)))
		*dst = '\0';
	return (srclen + dstlen);
}
