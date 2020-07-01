/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:02:20 by kachiote          #+#    #+#             */
/*   Updated: 2019/09/24 14:22:16 by kachiote         ###   ########.fr       */
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
