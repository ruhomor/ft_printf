/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:19:37 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/17 23:36:27 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_iswhitespace(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\n'))
		return (1);
	return (0);
}

static	char	*ft_skipspace(char const *s)
{
	while (ft_iswhitespace(*s))
		s++;
	return ((char*)s);
}

static	char	*ft_stomemcpy(char *mem, char const *s, char *ends)
{
	while (s != ends)
		*mem++ = *s++;
	*mem++ = *ends;
	*mem = '\0';
	return (mem);
}

static	char	*ft_skipspacebackwards(char *ends, char const *s)
{
	while (*ends)
		ends++;
	ends--;
	while ((ends != s) && (ft_iswhitespace(*ends)))
		ends--;
	return (ends);
}

char			*ft_strtrim(char const *s)
{
	char	*ends;
	char	*res;
	char	*mem;

	if (!s)
		return (NULL);
	ends = (char*)s;
	ends = ft_skipspacebackwards(ends, s);
	if ((ends == s) || (*s == '\0'))
	{
		if (!(res = ft_strnew(0)))
			return (NULL);
		*res = '\0';
		return (res);
	}
	s = (char const*)ft_skipspace(s);
	if (!(res = ft_strnew(ends - s + 1)))
		return (NULL);
	mem = res;
	mem = ft_stomemcpy(mem, (char*)s, ends);
	return (res);
}
