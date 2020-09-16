/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:43:29 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/16 13:12:11 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct	s_prnt
{
	va_list		*lst;
	char		type;
	int 		left; //FALSE
	char		sign_char; //''
	char		pad; //' '
	int 		alt_form; //FALSE
	int 		min_width; //0
	int 		precision; //-1
	char		prefix; //''
	int 		length; //0
	int			pad_zero; //0
	char        *c; //string pointer
	int 		len;
	int			size; //-1
}				t_prnt;

int		ft_printf(char *c, ...);
int		ft_printarg(t_prnt	info);
int		ft_sp_doxc(t_prnt	info);
int		ft_sp_u(t_prnt	info);
int		ft_sp_c(t_prnt	info);
char	*ft_ftoa(long double n, int precision);
int		ft_ifin(char c, const char *s);
int		ft_conversion(t_prnt info, char **c);
int		ft_flag(t_prnt info, char **c);
int		ft_if_zero_minus(long double zero);
char	*ft_itoa_basel(unsigned long long int nb, char base);

#endif
