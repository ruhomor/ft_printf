/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 12:50:14 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/16 15:10:19 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		ft_toupperchar(char c)
{
	if (ft_islowercase(c))
		return (c - 32);
	return (c);
}

char		*ft_chars(t_prnt info, int num)
{
	char *numstr;

	numstr = ft_strnew(1 * sizeof(char));
	*numstr = (char)num;
	return (numstr);
}

static int	ft_lennbl(unsigned long long int nb, char base)
{
	int len;

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

static int	ft_lennbh(unsigned short int nb, char base)
{
	int len;

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

static int	ft_lennbhh(unsigned char nb, char base)
{
	int len;

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

char		*ft_based_o(t_prnt info, long long int num)
{
	if (info.size == 1)
		return (ft_itoa_baseh(num, 8));
	else if (info.size == 2)
		return (ft_itoa_basehh(num, 8));
	else if (info.size == -1)
		return (ft_itoa_base(num, 8));
	else
		return (ft_itoa_basel(num, 8));
}

char		*ft_based_xp(t_prnt info, long long int num)
{
	if (info.size == 1)
		return (ft_itoa_baseh(num, 16));
	else if (info.size == 2)
		return (ft_itoa_basehh(num, 16));
	else if (info.size == -1)
		return (ft_itoa_base(num, 16));
	else
		return (ft_itoa_basel(num, 16));
}

char		*ft_based(t_prnt info, long long int num)
{
	char	*buf;
	char	*numstr;

	if (info.type == 'o')
		return (ft_based_o(info, num));
	else if (ft_ifin(info.type, "xp"))
		return (ft_based_xp(info, num));
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
		numstr = ft_strmap(buf, ft_toupperchar);
		free(buf);
		return (numstr);
	}
	else if (info.type == 'u')
		return (ft_itoa_basel(num, 10));
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

char		*ft_strnbr(t_prnt info, long long int num, char *sign_char)
{
	if (ft_ifin(info.type, "id"))
		return (ft_itoal(num, sign_char));
	else
	{
		if (ft_ifin(info.type, "ouxXp"))
			return (ft_based(info, num));
		else if (info.type == 'c')
			return (ft_chars(info, num));
	}
}

char		*read_arg_u(t_prnt info, char *sign_char, char **numstr)
{
	if (info.size == 1)
		*numstr = ft_strnbr(info, (unsigned short int)
		va_arg(*(info.lst), unsigned int), sign_char);
	else if (info.size == 2)
		*numstr = ft_strnbr(info, (unsigned char)
		va_arg(*(info.lst), unsigned int), sign_char);
	else if (info.size == 3)
		*numstr = ft_strnbr(info,
		va_arg(*(info.lst), unsigned long int), sign_char);
	else if (info.size == 4)
		*numstr = ft_strnbr(info,
		va_arg(*(info.lst), unsigned long long int), sign_char);
	else
		*numstr = ft_strnbr(info, va_arg(*(info.lst), unsigned int), sign_char);
}

char		*read_arg_not_u(t_prnt info, char *sign_char, char **numstr)
{
	if (info.size == 1)
		*numstr = ft_strnbr(info, (short int)
				va_arg(*(info.lst), int), sign_char);
	else if (info.size == 2)
		*numstr = ft_strnbr(info, (char)
				va_arg(*(info.lst), int), sign_char);
	else if (info.size == 3)
		*numstr = ft_strnbr(info,
							va_arg(*(info.lst), long int), sign_char);
	else if (info.size == 4)
		*numstr = ft_strnbr(info,
							va_arg(*(info.lst), long long int), sign_char);
	else
		*numstr = ft_strnbr(info,
						va_arg(*(info.lst), int), sign_char);
}

void		read_arg(t_prnt info, char *sign_char, char **numstr)
{
	if (info.type == 'p')
		*numstr = ft_strnbr(info, (unsigned long long int)
		va_arg(*(info.lst), void*), sign_char);
	else
	{
		if (info.type == 'u')
			read_arg_u(info, sign_char, numstr);
		else if (info.type == '%')
		{
			info.type = 'c';
			*numstr = ft_strnbr(info, '%', sign_char);
		}
		else
			read_arg_not_u(info, sign_char, numstr);
	}
}

void		ft_pudding(t_prnt info, char *numstr, char **str)
{
	int	numlen;

	numlen = ft_strlen(numstr);
	if (info.type == 'c' && !ft_strcmp(numstr, "\0"))
		numlen += 1;
	if (info.min_width > numlen)
	{
		*str = ft_strnew(info.min_width - numlen);
		ft_memset(*str, info.pad, info.min_width - numlen);
	}
	else
		*str = ft_strnew(0);
}

int			ft_printout_left(t_prnt info, char **str, char **numstr)
{
	if (info.type == 'c' && !ft_strcmp(*numstr, "\0"))
	{
		ft_putchar(0);
		info.len += 1;
	}
	ft_putstr(*numstr);
	if (*str)
	{
		ft_putstr(*str);
		info.len += ft_strlen(*str);
		free(*str);
	}
	return (info.len);
}

int			ft_printout(t_prnt info, char **str, char **numstr)
{
	if (info.left == 1)
		info.len += ft_printout_left(info, str, numstr);
	else
	{
		if (*str)
		{
			ft_putstr(*str);
			info.len += ft_strlen(*str);
			free(*str);
		}
		if (info.type == 'c' && !ft_strcmp(*numstr, "\0"))
		{
			ft_putchar(0);
			info.len += 1;
		}
		ft_putstr(*numstr);
	}
	info.len += ft_strlen(*numstr);
	free(*numstr);
	return (info.len);
}

void		ft_gluezeros(int zeros, char **numstr)
{
	char	*zerostring;
	char	*buf;

	zerostring = ft_strzeros(zeros);
	buf = *numstr;
	*numstr = ft_strjoin(zerostring, *numstr);
	free(buf);
	free(zerostring);
}

int			ft_formcounter(t_prnt info, char *numstr)
{
	if (ft_ifin(info.type, "di"))
	{
		if (info.sign_char)
			return (1);
	}
	if (ft_ifin(info.type, "xXp"))
	{
		if (info.alt_form == 1)
			return (2);
	}
	if (info.type == 'o')
	{
		if (info.alt_form == 1)
		{
			if (*numstr != '0')
				return (1);
		}
	}
	return (0);
}

void		ft_numstart_di(t_prnt info, char **numstr, char **sign)
{
	char	*buf;

	if (info.sign_char)
	{
		*sign = ft_strnew(1);
		**sign = info.sign_char;
		buf = *numstr;
		*numstr = ft_strjoin(*sign, *numstr);
		free(buf);
		free(*sign);
	}
}

void		ft_numstart_xxp(t_prnt info, char **numstr, char **sign)
{
	char	*buf;

	if (info.alt_form == 1)
	{
		if (ft_ifin(info.type, "xp"))
			*sign = ft_strdup("0x");
		else
			*sign = ft_strdup("0X");
		buf = *numstr;
		*numstr = ft_strjoin(*sign, *numstr);
		free(buf);
		free(*sign);
	}
}

void		ft_numstart(t_prnt info, char **numstr)
{
	char *buf;
	char *sign;

	if (ft_ifin(info.type, "di"))
		ft_numstart_di(info, numstr, &sign);
	if (ft_ifin(info.type, "xXp"))
		ft_numstart_xxp(info, numstr, &sign);
	if (info.type == 'o')
	{
		if (info.alt_form == 1)
		{
			if (**numstr != '0')
			{
				sign = ft_strnew(1);
				*sign = '0';
				buf = *numstr;
				*numstr = ft_strjoin(sign, *numstr);
				free(buf);
				free(sign);
			}
		}
	}
}

void			ft_sp_doxc_zero_prec_zero_doxc(t_prnt info,
									   char **numstr, char **str, int *numlen)
{
	if ((ft_ifin(info.type, "di") && (info.sign_char == '+')))
		**numstr = '+';
	else
	{
		free(*numstr);
		*numstr = ft_strnew(0);
	}
}

void			ft_sp_doxc_zero_prec_zero(t_prnt info,
								 char **numstr, char **str, int *numlen)
{
	info.pad = ' ';
	if (ft_ifin(info.type, "diuxXp"))
		ft_sp_doxc_zero_prec_zero_doxc(info, numstr, str, numlen);
	else if (info.type == 'o')
	{
		if (info.alt_form == 0)
		{
			free(*numstr);
			*numstr = ft_strnew(0);
		}
	}
	if (info.type == 'p')
		ft_numstart(info, numstr);
}

int 		ft_sp_doxc_zero_prec_not_zero(t_prnt info, char **numstr, char **str, int *numlen)
{
	if (info.precision >= 0)
	{
		info.pad = ' ';
		*numlen = ft_strlen(*numstr);
		if (info.type == 'c' && !ft_strcmp(*numstr, "\0"))
			*numlen += 1;
		if (info.precision > *numlen)
			ft_gluezeros(info.precision - *numlen, numstr);
		if (!(ft_ifin(info.type, "xX")))
			ft_numstart(info, numstr);
		*numlen = ft_strlen(*numstr);
		if (info.type == 'c' && !ft_strcmp(*numstr, "\0"))
			*numlen += 1;
		if (info.min_width > *numlen)
		{
			if (*str)
				free(*str);
			ft_pudding(info, *numstr, str);
		}
		return (ft_printout(info, str, numstr));
	}
	else
	{
		*numlen = ft_strlen(*numstr);
		if (info.type == 'c' && !ft_strcmp(*numstr, "\0"))
			*numlen += 1;
		if (info.min_width > *numlen)
		{
			if (info.pad == '0')
				ft_gluezeros(info.min_width - *numlen - ft_formcounter(info, *numstr), numstr);
			ft_numstart(info, numstr);
			if (info.pad == ' ')
			{
				if (*str)
					free(*str);
				ft_pudding(info, *numstr, str);
			}
		}
		else
		{
			if (!(ft_ifin(info.type, "xX")))
				ft_numstart(info, numstr);
		}
		return (ft_printout(info, str, numstr));
	}
}

int 		ft_sp_doxc_zero(t_prnt info, char **numstr, char **str)
{
	int 	numlen;

	if (info.precision == 0)
		ft_sp_doxc_zero_prec_zero(info, numstr, str, &numlen);
	else
		return (ft_sp_doxc_zero_prec_not_zero(info, numstr, str, &numlen));
	if (*str)
		free(*str);
	ft_pudding(info, *numstr, str);
	return (ft_printout(info, str, numstr));
}

int			ft_sp_doxc_new(t_prnt info)
{
	char	*numstr;
	int		numlen;
	char	*str;

	str = ft_strnew(0);
	if ((info.left == 1) && (info.pad == '0'))
		info.pad = ' ';
	read_arg(info, &info.sign_char, &numstr);
	if (!(ft_strcmp("0", numstr)))
		return (ft_sp_doxc_zero(info, &numstr, &str));
	if (info.precision >= 0)
	{
		info.pad = ' ';
		numlen = ft_strlen(numstr);
		if (info.type == 'c' && !ft_strcmp(numstr, "\0"))
			numlen += 1;
		if ((info.precision > numlen) && (info.type != 'c'))
			ft_gluezeros(info.precision - numlen, &numstr);
		ft_numstart(info, &numstr);
		numlen = ft_strlen(numstr);
		if (info.type == 'c' && !ft_strcmp(numstr, "\0"))
			numlen += 1;
		if (info.min_width > numlen)
		{
			if (str)
				free(str);
			ft_pudding(info, numstr, &str);
		}
		return (ft_printout(info, &str, &numstr));
	}
	else
	{
		numlen = ft_strlen(numstr);
		if (info.type == 'c' && !ft_strcmp(numstr, "\0"))
			numlen += 1;
		if (info.min_width > numlen)
		{
			if (info.pad == '0')
				ft_gluezeros(info.min_width - numlen - ft_formcounter(info, numstr), &numstr);
			ft_numstart(info, &numstr);
			if (info.pad == ' ')
			{
				if (str)
					free(str);
				ft_pudding(info, numstr, &str);
			}
		}
		else
			ft_numstart(info, &numstr);
		return (ft_printout(info, &str, &numstr));
	}
}

int			ft_sp_s(t_prnt info)
{
	char	*numstr;
	int		numlen;
	char	*str;
	char	*buf;
	int		clear;

	str = 0;
	clear = FALSE;
	if ((info.left == 1) && (info.pad == '0'))
		info.pad = ' ';
	numstr = va_arg(*(info.lst), char *);
	if (!(numstr))
	{
		numstr = ft_strdup("(null)");
		clear = TRUE;
	}
	numlen = ft_strlen(numstr);
	if ((info.precision != -1) && (numlen > info.precision))
	{
		ft_strncpy(buf = ft_strnew(info.precision), numstr, info.precision);
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
	info.len += ft_strlen(numstr);
	if (clear)
		free(numstr);
	return (info.len);
}

int			ft_sp_f(t_prnt info)
{
	char	*numstr;
	int		numlen;
	char	*str;

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

	int			(*parg[12])();
	const char	*blabs = "diouxXc%fFsp";

	if (!ft_ifin(info.type, blabs))
	{
		ft_putchar(info.type);
		return (1);
	}
	parg[0] = ft_sp_doxc_new;
	parg[1] = ft_sp_doxc_new;
	parg[2] = ft_sp_doxc_new;
	parg[3] = ft_sp_doxc_new;
	parg[4] = ft_sp_doxc_new;
	parg[5] = ft_sp_doxc_new;
	parg[6] = ft_sp_doxc_new;
	parg[7] = ft_sp_doxc_new;
	parg[8] = ft_sp_f;
	parg[9] = ft_sp_f;
	parg[10] = ft_sp_s;
	parg[11] = ft_sp_doxc_new;
	return (parg[ft_strchr(blabs, info.type) - blabs](info));
}

void		ft_prnt_init(t_prnt *info)
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
	va_list	lst;
	t_prnt	info;
	int		res;

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
		if (*c != '\0')
			c++;
	}
	va_end(lst);
	return (res);
}
