/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backwardsmemcpy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:39:21 by kachiote          #+#    #+#             */
/*   Updated: 2019/09/23 20:42:04 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_backwardsmemcpy(void *dst, const void *src, size_t n)
{
	unsigned char *bdst;
	unsigned char *bsrc;

	if (src || dst)
	{
		bdst = (unsigned char*)dst;
		bsrc = (unsigned char*)src;
		bdst += (n - 1);
		bsrc += (n - 1);
		while (n--)
		{
			*bdst = *bsrc;
			bdst--;
			bsrc--;
		}
		return (dst);
	}
	return (NULL);
}
