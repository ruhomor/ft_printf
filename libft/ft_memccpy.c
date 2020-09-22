/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:29:14 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/17 23:36:27 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *bdst;
	unsigned char *bsrc;
	unsigned char a;

	a = (unsigned char)c;
	bdst = (unsigned char*)dst;
	bsrc = (unsigned char*)src;
	if (dst || src)
	{
		while (n--)
		{
			*bdst = *bsrc;
			if (*bdst == a)
			{
				bdst++;
				return (bdst);
			}
			bdst++;
			bsrc++;
		}
	}
	return (NULL);
}
