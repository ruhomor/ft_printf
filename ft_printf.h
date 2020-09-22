/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:43:29 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/22 11:59:11 by sslift           ###   ########.fr       */
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
	int			left;
	char		sign_char;
	char		pad;
	int			alt_form;
	int			min_width;
	int			precision;
	char		prefix;
	int			length;
	int			pad_zero;
	char		*c;
	int			len;
	int			size;
}				t_prnt;

int				ft_printf(char *c, ...);
int				ft_printarg(t_prnt	info);
int				ft_sp_doxc(t_prnt	info);
int				ft_sp_u(t_prnt	info);
int				ft_sp_c(t_prnt	info);
char			*ft_ftoa(long double n, int precision);
int				ft_ifin(char c, const char *s);
int				ft_conversion(t_prnt info, char **c);
int				ft_flag(t_prnt info, char **c);
int				ft_if_zero_minus(long double zero);
char			*ft_itoa_basel(unsigned long long int nb, char base);
int				ft_lennbl(unsigned long long int nb, char base);
int				ft_lennbh(unsigned short int nb, char base);
int				ft_lennbhh(unsigned char nb, char base);
char			*ft_itoa_basel(unsigned long long int nb, char base);
char			*ft_itoa_baseh(unsigned short int nb, char base);
char			*ft_itoa_basehh(unsigned char nb, char base);
char			*ft_itoal(long long int n, char *sign);
char			*ft_based_o(t_prnt info, long long int num);
char			*ft_based_xp(t_prnt info, long long int num);
char			*ft_based(t_prnt info, long long int num);
char			ft_toupperchar(char c);
char			*ft_chars(t_prnt info, int num);
void			ft_writenbrl(char *s, unsigned long long int n, int size);
char			*ft_strnbr(t_prnt info, long long int num, char *sign_char);
char			*read_arg_u(t_prnt info, char *sign_char, char **numstr);
char			*read_arg_not_u(t_prnt info, char *sign_char, char **numstr);
void			read_arg(t_prnt info, char *sign_char, char **numstr);
void			ft_pudding(t_prnt info, char *numstr, char **str);
int				ft_printout_left(t_prnt info, char **str, char **numstr);
int				ft_printout(t_prnt info, char **str, char **numstr);
void			ft_gluezeros(int zeros, char **numstr);
int				ft_formcounter(t_prnt info, char *numstr);
void			ft_numstart_di(t_prnt info, char **numstr, char **sign);
void			ft_numstart_xxp(t_prnt info, char **numstr, char **sign);
void			ft_numstart(t_prnt info, char **numstr);
void			ft_sp_doxc_zero_prec_zero_doxc(t_prnt info, char **numstr);
void			ft_sp_doxc_zero_prec_zero(t_prnt info, char **numstr);
int				ft_sp_doxc_zero_prec_not_zero_neg(t_prnt info, char **numstr,
										char **str, int *numlen);
int				ft_sp_doxc_zero_prec_not_zero(t_prnt info, char **numstr,
									char **str, int *numlen);
int				ft_sp_doxc_zero(t_prnt info, char **numstr, char **str);
int				ft_sp_doxc_new_prec_pos(t_prnt info, char **numstr,
							char **str, int *numlen);
int				ft_sp_doxc_new_prec_neg(t_prnt info, char **numstr,
							char **str, int *numlen);
int				ft_sp_doxc_new(t_prnt info);
int				ft_sp_s_printout(t_prnt info, char **numstr,
						char **str, int clear);
void			ft_sp_s_meme(t_prnt info, char **numstr, int *numlen);
int				ft_sp_s(t_prnt info);
int				ft_sp_f_printout(t_prnt info, char **numstr, char **str);
int				ft_sp_f(t_prnt info);

#endif
