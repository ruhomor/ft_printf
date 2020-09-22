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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *bdst;
	unsigned char *bsrc;

	if (src || dst)
	{
		bdst = (unsigned char*)dst;
		bsrc = (unsigned char*)src;
		while (n--)
		{
			*bdst = *bsrc;
			bdst++;
			bsrc++;
		}
		return (dst);
	}
	return (NULL);
}
