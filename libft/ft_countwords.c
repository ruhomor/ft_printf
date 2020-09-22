/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:37:41 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/17 23:36:27 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(char const *s, char delim)
{
	short int	isword;
	size_t		words;

	words = 0;
	isword = 0;
	while (*s)
	{
		if ((*s != delim) && (isword == 0))
		{
			isword = 1;
			words++;
		}
		if (*s == delim)
			isword = 0;
		s++;
	}
	return (words);
}
