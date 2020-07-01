/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:44:20 by kachiote          #+#    #+#             */
/*   Updated: 2019/09/24 14:32:13 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	ft_cmpl(const char *hs, const char *n, size_t len)
{
	while ((*n) && (*hs == *n) && (len--))
	{
		hs++;
		n++;
	}
	if (*n == '\0')
		return (1);
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char*)haystack);
	while ((*haystack) && (len))
	{
		if (*needle == *haystack)
			if (ft_cmpl(haystack, needle, len))
				return ((char*)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
