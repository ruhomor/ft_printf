/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:03:33 by kachiote          #+#    #+#             */
/*   Updated: 2019/09/23 20:39:55 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst || src)
	{
		if (dst <= src)
			return (ft_memcpy(dst, src, len));
		else
			return (ft_backwardsmemcpy(dst, src, len));
	}
	return (NULL);
}
