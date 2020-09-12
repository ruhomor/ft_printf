/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 19:08:16 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/04 23:19:18 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

//double modf(double x, double *iptr)
//{
//    union {double f; uint64_t i;} u = {x};
//    uint64_t mask;
//    int e = (int)(u.i>>52 & 0x7ff) - 0x3ff;
//
//    /* no fractional part */
//    if (e >= 52) {
//        *iptr = x;
//        if (e == 0x400 && u.i<<12 != 0) /* nan */
//            return x;
//        u.i &= 1ULL<<63;
//        return u.f;
//    }
//
//    /* no integral part*/
//    if (e < 0) {
//        u.i &= 1ULL<<63;
//        *iptr = u.f;
//        return x;
//    }
//
//    mask = -1ULL>>12>>e;
//    if ((u.i & mask) == 0) {
//        *iptr = x;
//        u.i &= 1ULL<<63;
//        return u.f;
//    }
//    u.i &= ~mask;
//    *iptr = u.f;
//    return x - u.f;
//}

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
