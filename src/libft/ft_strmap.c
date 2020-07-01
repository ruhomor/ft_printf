/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:43:53 by kachiote          #+#    #+#             */
/*   Updated: 2019/09/24 14:25:25 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	char	*mem;

	if (s && f && (res = ft_strnew(ft_strlen(s))))
	{
		mem = res;
		while (*s)
			*mem++ = (*f)(*s++);
		*mem = '\0';
		return (res);
	}
	return (NULL);
}
