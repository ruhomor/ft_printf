/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:32:26 by kachiote          #+#    #+#             */
/*   Updated: 2019/09/24 14:28:31 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	char			*mem;
	unsigned int	i;

	if (s && f && (res = ft_strnew(ft_strlen(s))))
	{
		mem = res;
		i = 0;
		while (*s)
		{
			*mem++ = (*f)(i, *s++);
			i++;
		}
		*mem = '\0';
		return (res);
	}
	return (NULL);
}
