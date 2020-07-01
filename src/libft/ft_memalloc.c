/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:08:18 by kachiote          #+#    #+#             */
/*   Updated: 2019/09/24 18:12:24 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *suka;

	if (!(suka = malloc(size)))
		return (NULL);
	suka = ft_memset(suka, '\0', size);
	return (suka);
}
