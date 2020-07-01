/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:37:39 by kachiote          #+#    #+#             */
/*   Updated: 2019/09/22 15:57:40 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*mem;

	if (s && (res = ft_strnew(len)))
	{
		s += start;
		mem = res;
		while (len--)
			*mem++ = *s++;
		*mem = '\0';
		return (res);
	}
	return (NULL);
}
