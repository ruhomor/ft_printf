/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:43:29 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/04 23:19:18 by sslift           ###   ########.fr       */
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
	int			sign_char; //''
	char		pad; //' '
	int 		alt_form; //FALSE
	int 		min_width; //0
	int 		precision; //-1
	char		prefix; //''
	int 		length; //0
	int			pad_zero; //0
	char        *c; //string pointer
	char *		size;
}				t_prnt;

void	ft_printf(char *c, ...);
void	ft_printarg(t_prnt	info);
void	ft_sp_dox(t_prnt	info);
void	ft_sp_u(t_prnt	info);
void	ft_sp_c(t_prnt	info);
void	ft_sp_perc(void);
char    *ft_ftoa(long double n, int precision);
int 	ft_ifin(char c, const char *s);
void	ft_conversion(t_prnt info, char **c);
void 	ft_flag(t_prnt info, char **c);

#endif
