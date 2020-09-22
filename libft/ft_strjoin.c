/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:58:57 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/17 23:36:27 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*mem;

	if ((s1) && (s2) && (res = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		mem = res;
		while (*s1)
			*mem++ = *s1++;
		while (*s2)
			*mem++ = *s2++;
		*mem = '\0';
		return (res);
	}
	return (NULL);
}
