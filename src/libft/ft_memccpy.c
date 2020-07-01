/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:29:14 by kachiote          #+#    #+#             */
/*   Updated: 2019/09/15 14:26:31 by kachiote         ###   ########.fr       */
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
