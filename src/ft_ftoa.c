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

char    *ft_ftoa(double n, int precision)
{
    char *res;
    int u;
    //TODO change from int to uint_64
    //unsigned long long u;
    double f;
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
    f = .4;
    while (0 < pr--)
        f /= 10;
    n += f;
    u = (int)n;
    f = n - u;
//    if (precision <= 0 && ft_round_below_one(f))
//        u++; //TODO check переполнение
    printf("debug %d %f\n", u, f);
    ft_strcat(res, ft_itoa(u));
    if (precision > 0)
        ft_strcat(res, ".");
    while (0 < precision--)
    {
        f *= 10;
        printf("f=%f\n", f);
        u = (int)f;
        printf("u=%u\n", u);
        f -= u;
        printf("debug %d %f pr=%d\n", u, f, precision);
        ft_strcat(res, ft_itoa(u));
    }
    return res;
}