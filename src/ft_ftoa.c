/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 19:08:16 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/17 23:36:26 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_ftoa(long double n, int precision)
{
    char *res;
    unsigned long long int u;
    long double f;
    int pr;

    if (precision < 0)
        precision = 6;
    res = ft_strnew(0);
    if (n < 0)
    {
        ft_strcat(res, "-");
        n = -n;
    }
    pr = precision;
    f = .5;
    while (0 < pr--)
        f /= 10;
    n += f;
    u = (unsigned long long int)n;
    f = n - u;
    ft_strcat(res, ft_itoa_basel(u, 10));
    if (precision > 0)
        ft_strcat(res, ".");
    while (0 < precision--)
    {
        f *= 10;
        u = (unsigned long long int)f;
        f -= u;
        ft_strcat(res, ft_itoa_basel(u, 10));
    }
    return res;
}
