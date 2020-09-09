/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 12:50:14 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/08 01:53:56 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>  //  TODO REMOVE

char		ft_toupperchar(char c)
{
	if (ft_islowercase(c))
		return (c - 32);
	return (c);
}

int		ft_handle_h(t_prnt info, char **numstr, long long int num)
{
	char	*buf;

	if ((info.type == 'o') && (**numstr != '0') && (**numstr != '\0')) //condition 0
	{
		buf = *numstr;
		*numstr = ft_strjoin("0", *numstr);
		free(buf);
		return (1);
	}
	else if (info.type == 'x') //  condition 0x
	{
		buf = *numstr;
		*numstr = ft_strjoin("0x", *numstr);
		free(buf);
		return (2);
	}
	else if (info.type == 'X')
	{
		buf = *numstr;
		*numstr = ft_strjoin("0X", *numstr);  //  condition 0X
		free(buf);
		return (2);
	}
	return (0);
}

void		ft_chars(t_prnt info, char **numstr, int num)
{
	*numstr = ft_strnew(1 * sizeof(char));
	**numstr = (char)num;
}

static int		ft_lennbl(unsigned long long int nb, char base)
{
	int			len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}

char			*ft_itoa_basel(unsigned long long int nb, char base)
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

static int		ft_lennbh(unsigned short int nb, char base)
{
	int			len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}

char			*ft_itoa_baseh(unsigned short int nb, char base)
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

static int		ft_lennbhh(unsigned char nb, char base)
{
	int			len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}

char			*ft_itoa_basehh(unsigned char nb, char base)
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

void		ft_based(t_prnt info, char **numstr, long long int num)
{
	char	*buf;

	if (info.type == 'o')
	{
		if (info.size == 1)
			*numstr = ft_itoa_baseh(num, 8);
		else if (info.size == 2)
			*numstr = ft_itoa_basehh(num, 8);
		else if (info.size == -1)
			*numstr = ft_itoa_base(num, 8);
		else
			*numstr = ft_itoa_basel(num, 8);
	}
	else if (info.type == 'x')
	{
		if (info.size == 1)
			*numstr = ft_itoa_baseh(num, 16);
		else if (info.size == 2)
			*numstr = ft_itoa_basehh(num, 16);
		else if (info.size == -1)
			*numstr = ft_itoa_base(num, 16);
		else
			*numstr = ft_itoa_basel(num, 16);
	}
	else if (info.type == 'X')
	{
		if (info.size == 1)
			buf = ft_itoa_baseh(num, 16);
		else if (info.size == 2)
			buf = ft_itoa_basehh(num, 16);
		else if (info.size == -1)
			buf = ft_itoa_base(num, 16);
		else
			buf = ft_itoa_basel(num, 16);
		*numstr = ft_strmap(buf, ft_toupperchar);
		free(buf);
	}
	else if (info.type == 'u')
		*numstr = ft_itoa_basel(num, 10);
}

void		ft_writenbrl(char *s, unsigned long long int n, int size)
{
	char	*buf;

	if (n == 0)
		*s = '0';
	buf = s + size - 1;
	while (n)
	{
		*buf = (n % 10) + '0';
		n /= 10;
		buf--;
	}
}

static	int	ft_reqsizel(long long int n)
{
	int		res;

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

char		*ft_itoal(long long int n)
{
	int						rsize;
	unsigned long long int	un;
	short int				sign;
	char					*res;

	sign = 0;
	if (n < 0)
	{
		sign = 1;
		un = -n;
	}
	else
		un = n;
	rsize = ft_reqsizel(n) + sign;
	if (!(res = ft_strnew(rsize)))
		return (NULL);
	res[rsize] = '\0';
	if (sign == 1)
		*res = '-';
	ft_writenbrl(res, un, rsize);
	return (res);
}

size_t		ft_converse(t_prnt info, long long int num, char **numstr)
{
	size_t	len;
    //if (ft_ifin(info.type, "idu"))
	if (((info.precision == 0) && (num == 0)) && (ft_ifin(info.type, "iduoxX")))
		*numstr = ft_strnew(0);
	else if (ft_ifin(info.type, "id"))
		*numstr = ft_itoal(num);  //  allocs numstr
	else if (ft_ifin(info.type, "ouxX"))
		ft_based(info, numstr, num);
	else if (info.type == 'c')
	{
		ft_chars(info, numstr, num);
		return (1);
	}
	len = ft_strlen(*numstr);
	if ((info.alt_form == 1) && (num != 0)) //why (num != 0) ?
		len -= ft_handle_h(info, numstr, num);
	if (ft_ifin(info.type, "id") && (num < 0))
		len -= 1;
	return (len);
	//return (ft_strlen(*numstr) - ft_ifin(info.type, "id") * (num < 0)
	//		- (info.alt_form) * ((2 * ft_ifin(info.type, "xX")
	//			+ (info.type == 'o')))* (num != 0));
}

void		ft_manageplus(t_prnt info, char **numstr, long long int num)
{
	char	*buf;

	if ((num > 0) * ft_ifin(info.type, "id") && (info.sign_char == '+'))
	{
		buf = *numstr;
		*numstr = ft_strjoin("+", *numstr);
		free(buf);
	}
	if (info.sign_char == ' ')
	{
		buf = *numstr;
		*numstr = ft_strjoin(" ", *numstr);
		free(buf);
	}
}

void		ft_formnsign(t_prnt info, char **numstr, long long int num)
{
	char	*buf;

	if ((num < 0) * ft_ifin(info.type, "id")) //add - for decimal condition
	{
		buf = *numstr;
		*numstr = ft_strjoin("-", *numstr);
		free(buf);
	}
	if ((info.alt_form == 1) && (num != 0))
	{
		if (info.type == 'x') //add 0x for hexa condition
		{
			buf = *numstr;
			*numstr = ft_strjoin("0x", *numstr);
			free(buf);
		}
		if (info.type == 'X')  //add 0X for hexa condition
		{
			buf = *numstr;
			*numstr = ft_strjoin("0X", *numstr);
			free(buf);
		}
		else if ((info.type == 'o') && (**numstr != '0') && (**numstr != '\0')) //add 0 for octal condition
		{
			buf = *numstr;
			*numstr = ft_strjoin("0", *numstr);
			free(buf);
		}
	}
}

char		*ft_precise(t_prnt info, long long int num)
{
	char	*numstr;
	char	*buf;
	int		numlen;
	int 	shift;
	int		zeros;

	shift = 0;
	numlen = ft_converse(info, num, &numstr);
	if ((info.precision > (numlen)) && (!(info.type == 'c')))
	{
		buf = numstr;
		if (ft_ifin(info.type, "id") && (num < 0)) // add - for decimal condition
			shift += 1;
		if (ft_ifin(info.type, "xX") && (info.alt_form == 1) && (num != 0)) // add 0x for hex condition
			shift += 2;
		if ((info.type == 'o') && (info.alt_form == 1) && (num != 0) && (*numstr != '0') && (*numstr != '\0')) // add 0 for octal condition
			shift += 1;
		zeros = info.precision - numlen - shift;
		if (zeros >= 0)
			numstr = ft_strjoin(ft_strzeros(zeros), numstr + shift);
		else
			numstr = ft_strjoin(ft_strzeros(0), numstr + shift);
		free(buf);
		ft_formnsign(info, &numstr, num);
	}
	ft_manageplus(info, &numstr, num);
	if ((info.type == 'o') && (info.alt_form == 1) && (num == 0))
		numstr = ft_strzeros(1);
	return (numstr);
}

int	ft_print_pad(t_prnt info, char **str, char **numstr)
{
	if (info.left)
	{
		ft_putstr(*numstr);
		info.len += ft_strlen(*numstr);
		free(*numstr);  //  frees numstr
		if (*str)
		{
			ft_putstr(*str);
			info.len += ft_strlen(*str);
			free(*str);  //  frees str
		}
	}
	else
	{
		if (*str)
		{
			ft_putstr(*str);
			info.len += ft_strlen(*str);
			free(*str);  //  frees str
		}
		ft_putstr(*numstr);
		info.len += ft_strlen(*numstr);
		free(*numstr);  //  frees num
	}
	return (info.len);
}

void	ft_manageminus(t_prnt info, char **str, char **numstr)
{
	char	*buf;
	char	*ddel;

	if ((*str) && (**str == '0') && (*numstr) && (**numstr == '-'))
	{
		ddel = *str;
		buf = ft_strdup("-");
		ft_strcat(buf, *str);
		*str = buf;
		free(ddel);
		ddel = *numstr;
		buf = ft_strnew(0);
		ft_strcat(buf, *numstr + 1);
		*numstr = buf;
		free(ddel);
	}
}

char		*read_arg(t_prnt info)
{
	char	*numstr;

	if (info.type == 'u')
	{
		if (info.size == 1)
			numstr = ft_precise(info, (unsigned short int)va_arg(*(info.lst), unsigned int));
		else if (info.size == 2)
			numstr = ft_precise(info, (unsigned char)va_arg(*(info.lst), unsigned int));
		else if (info.size == 3)
			numstr = ft_precise(info, va_arg(*(info.lst), unsigned long int));
		else if (info.size == 4)
			numstr = ft_precise(info, va_arg(*(info.lst), unsigned long long int));
		else
			numstr = ft_precise(info, va_arg(*(info.lst), unsigned int));
	}
	else if (info.type == '%')
	{
		info.type = 'c';
		numstr = ft_precise(info, '%');
	}
	else
	{
		if (info.size == 1)
			numstr = ft_precise(info, (short int)va_arg(*(info.lst), int));
		else if (info.size == 2)
			numstr = ft_precise(info, (char)va_arg(*(info.lst), int));
		else if (info.size == 3)
			numstr = ft_precise(info, va_arg(*(info.lst), long int));
		else if (info.size == 4)
			numstr = ft_precise(info, va_arg(*(info.lst), long long int));
		else
			numstr = ft_precise(info, va_arg(*(info.lst), int));
	}
	return (numstr);
}

int		ft_sp_doxc(t_prnt info)
{
	char	*numstr;
	int		numlen;
	char	*str;

	numstr = read_arg(info);
	if (info.precision != -1)
		info.pad = ' ';
	if ((info.left == 1) && (info.pad == '0')) //  ignore '0' if '-' is present
		info.pad = ' ';
	str = NULL;
	numlen = ft_strlen(numstr) + (info.type == 'c') * (*numstr == '\0');
	if (info.min_width > numlen)
	{
		str = ft_strnew(info.min_width - numlen);
		ft_memset(str, info.pad, info.min_width - numlen);
	}
	ft_manageminus(info, &str, &numstr);
	info.len = ft_print_pad(info, &str, &numstr);
	return (info.len);
}

int		ft_sp_s(t_prnt info)
{
	char	*numstr;
	int		numlen;
	char	*str;
	char	*buf;
	int		clear;

	str = 0;
	clear = FALSE;
    //if (info.precision != -1)
    //    info.pad = ' ';
	if ((info.left == 1) && (info.pad == '0')) //  ignore '0' if '-' is present
		info.pad = ' ';
	numstr = va_arg(*(info.lst), char *);  //  does it allocs - MALLOCS??????
	if (!(numstr))
	{
		numstr = ft_strdup("(null)");
		clear = TRUE;
	}
	numlen = ft_strlen(numstr);
	if ((info.precision != -1) && (numlen > info.precision))
	{
		ft_strncpy(buf = ft_strnew(info.precision), numstr, info.precision);
        //free(numstr);
		numstr = buf;
		numlen = info.precision;
	}
	if (numlen < info.min_width)
	{
		str = ft_strnew(info.min_width - numlen);
		ft_memset(str, info.pad, info.min_width - numlen);
	}
	if (info.left == 1)
	{
		ft_putstr(numstr);
		if (str)
		{
			ft_putstr(str);
			info.len += ft_strlen(str);
			free(str);
		}
	}
	else
	{
		if (str)
		{
			ft_putstr(str);
			info.len += ft_strlen(str);
			free(str);
		}
		ft_putstr(numstr);
	}
	if (clear)
	{
		info.len += ft_strlen(numstr);
		free(numstr);
	}
	return (info.len);
}

int			ft_sp_f(t_prnt info)
{
	char		*numstr;
	int			numlen;
	char		*str;

	str = NULL;
	if (info.size == 5)
		numstr = ft_ftoa(va_arg(*(info.lst), long double), info.precision);
	else
		numstr = ft_ftoa(va_arg(*(info.lst), double), info.precision);
	numlen = ft_strlen(numstr);
	if (numlen < info.min_width)
	{
		str = ft_strnew(info.min_width - numlen);
		ft_memset(str, info.pad, info.min_width - numlen);
	}
	if (info.left == 1)
	{
		ft_putstr(numstr);
		if (str)
		{
			ft_putstr(str);
			info.len += ft_strlen(str);
			free(str);
		}
	}
	else
	{
		if (str)
		{
			ft_putstr(str);
			info.len += ft_strlen(str);
			free(str);
		}
		ft_putstr(numstr);
	}
	info.len += ft_strlen(numstr);
	free(numstr);
	return (info.len);
}

int			ft_printarg(t_prnt info)
{
	int		(*parg[11]) ();
	const char	*blabs = "diouxXc%fFs";//fF";

	if (!ft_ifin(info.type, blabs))
	{
		ft_putchar(info.type);
		return (1);
	}
	parg[0] = ft_sp_doxc;
	parg[1] = ft_sp_doxc;
	parg[2] = ft_sp_doxc;
	parg[3] = ft_sp_doxc;
	parg[4] = ft_sp_doxc;
	parg[5] = ft_sp_doxc;
	parg[6] = ft_sp_doxc;
	parg[7] = ft_sp_doxc;
	parg[8] = ft_sp_f;
	parg[9] = ft_sp_f;
	parg[10] = ft_sp_s;
	return (parg[ft_strchr(blabs, info.type) - blabs](info));
}

void			ft_prnt_init(t_prnt *info)
{
	info->sign_char = '\0';
	info->min_width = 0;
	info->pad = ' ';
	info->alt_form = 0;
	info->left = 0;
	info->length = 0;
	info->pad_zero = 0;
	info->precision = -1;
	info->prefix = '\0';
	info->len = 0;
	info->type = 0;
}

int			ft_printf(char *c, ...)
{
	va_list		lst;
	t_prnt		info;
	int 		res;

	res = 0;
	va_start(lst, c);
	info.lst = &lst;
	ft_prnt_init(&info);
	while (*c != '\0')
	{
		if (*c != '%')
		{
			ft_putchar(*c);
			res++;
		}
		else
		{
			c++;
			res += ft_flag(info, &c);
		}
		c++;
	}
	va_end(lst);
	return (res);
}
