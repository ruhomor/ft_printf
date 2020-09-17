/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslift <sslift@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 23:54:08 by sslift            #+#    #+#             */
/*   Updated: 2020/09/17 23:56:01 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_basel(unsigned long long int nb, char base)
{
	char		*str;
	int			len;
	int			i;
	const char	*cnst = "0123456789abcdef";

	len = ft_lennbl(nb, base);
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (nb == 0)
		*str = '0';
	i = len - 1;
	while ((i >= 0) && (nb != 0))
	{
		*(str + i) = *(cnst + (nb % base));
		nb /= base;
		i--;
	}
	*(str + len) = '\0';
	return (str);
}

char		*ft_itoa_baseh(unsigned short int nb, char base)
{
	char		*str;
	int			len;
	int			i;
	const char	*cnst = "0123456789abcdef";

	len = ft_lennbh(nb, base);
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (nb == 0)
		*str = '0';
	i = len - 1;
	while ((i >= 0) && (nb != 0))
	{
		*(str + i) = *(cnst + (nb % base));
		nb /= base;
		i--;
	}
	*(str + len) = '\0';
	return (str);
}

char		*ft_itoa_basehh(unsigned char nb, char base)
{
	char		*str;
	int			len;
	int			i;
	const char	*cnst = "0123456789abcdef";

	len = ft_lennbhh(nb, base);
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (nb == 0)
		*str = '0';
	i = len - 1;
	while ((i >= 0) && (nb != 0))
	{
		*(str + i) = *(cnst + (nb % base));
		nb /= base;
		i--;
	}
	*(str + len) = '\0';
	return (str);
}

static int	ft_reqsizel(long long int n)
{
	int	res;

	if (n == 0)
		return (1);
	res = 0;
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char		*ft_itoal(long long int n, char *sign)
{
	int						rsize;
	unsigned long long int	un;
	char					*res;

	if (n < 0)
	{
		*sign = '-';
		un = -n;
	}
	else
		un = n;
	rsize = ft_reqsizel(n);
	if (!(res = ft_strnew(rsize)))
		return (NULL);
	res[rsize] = '\0';
	ft_writenbrl(res, un, rsize);
	return (res);
}