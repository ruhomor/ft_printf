/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strzeros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:29:40 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/22 11:36:17 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strzeros(size_t size)
{
	char	*cuckoo;
	char	*mem;

	if (!(cuckoo = (char*)ft_memalloc(size + 1)))
		return (NULL);
	mem = cuckoo;
	while (size--)
		*mem++ = '0';
	*mem = '\0';
	return (cuckoo);
}
