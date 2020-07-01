/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:57:13 by kachiote          #+#    #+#             */
/*   Updated: 2019/09/24 14:30:38 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char a;
	char *buf;

	buf = 0;
	a = (char)c;
	while (*s)
	{
		if (a == *s)
			buf = (char*)s;
		s++;
	}
	if (*s == a)
		return ((char*)s);
	return (buf);
}
