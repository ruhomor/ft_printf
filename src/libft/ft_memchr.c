/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:50:47 by kachiote          #+#    #+#             */
/*   Updated: 2019/09/15 14:25:06 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char a;
	unsigned char *bs;

	bs = (unsigned char*)s;
	a = (unsigned char)c;
	while (n--)
	{
		if (*bs++ == a)
			return ((void*)--bs);
	}
	return (0);
}
