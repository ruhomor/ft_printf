/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:43:29 by kachiote          #+#    #+#             */
/*   Updated: 2020/08/24 22:59:28 by sslift           ###   ########.fr       */
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
}				t_prnt;

void	ft_printf(char *c, ...);
void	ft_printarg(t_prnt	info);
void	ft_sp_d(t_prnt	info);
void	ft_sp_u(t_prnt	info);
void	ft_sp_o(t_prnt	info);
void	ft_sp_x(t_prnt	info);
void	ft_sp_X(t_prnt	info);
void	ft_sp_c(t_prnt	info);
void	ft_sp_perc(void);

#endif
