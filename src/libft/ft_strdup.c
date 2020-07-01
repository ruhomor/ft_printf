/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:54:45 by kachiote          #+#    #+#             */
/*   Updated: 2019/09/24 18:11:51 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;
	char	*bs1;

	bs1 = (char*)s1;
	len = ft_strlen(s1);
	if (!(s2 = (char*)malloc(sizeof(*s2) * (len + 1))))
		return (NULL);
	s2[len] = '\0';
	while (*bs1)
	{
		*s2 = *bs1;
		bs1++;
		s2++;
	}
	return (s2 - len);
}
