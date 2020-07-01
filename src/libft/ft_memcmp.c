/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:44:36 by kachiote          #+#    #+#             */
/*   Updated: 2019/09/15 14:31:36 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *bs1;
	unsigned char *bs2;

	bs1 = (unsigned char*)s1;
	bs2 = (unsigned char*)s2;
	while (n--)
	{
		if (*bs1 != *bs2)
			return ((int)(*bs1 - *bs2));
		bs1++;
		bs2++;
	}
	return (0);
}
