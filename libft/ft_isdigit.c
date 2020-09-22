/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:07:07 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/17 23:36:27 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if ((c == '0') || (c == '1') || (c == '2') || (c == '3') || (c == '4')
		|| (c == '5') || (c == '6') || (c == '7') || (c == '8') || (c == '9'))
		return (1);
	return (0);
}
