/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:15:10 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/17 23:36:27 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_sstrlen(char const *s, char delim)
{
	char *b;

	b = (char*)s;
	while (*b && (*b != delim))
		b++;
	return ((size_t)(b - s));
}

char			**ft_strsplit(char const *s, char c)
{
	char		**res;
	char		**buf;
	size_t		words;
	short int	isword;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	if (!(res = (char**)malloc(sizeof(*res) * (words + 1))))
		return (NULL);
	res[words] = NULL;
	buf = res;
	isword = 0;
	while (*s)
	{
		if ((*s != c) && (isword == 0))
		{
			isword = 1;
			if (!(*res++ = ft_strsub(s, 0, ft_sstrlen(s, c))))
				return (ft_deldel((void**)buf));
		}
		if (*s++ == c)
			isword = 0;
	}
	return (buf);
}
