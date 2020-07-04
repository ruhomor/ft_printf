/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:43:29 by kachiote          #+#    #+#             */
/*   Updated: 2020/07/03 14:43:30 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

void	ft_printf(char *c, ...);
void	ft_printarg(va_list *lst, char type);
void	ft_sp_d(va_list *lst);
void	ft_sp_u(va_list *lst);
void	ft_sp_o(va_list *lst);
void	ft_sp_x(va_list *lst);
void	ft_sp_X(va_list *lst);
void	ft_sp_c(va_list *lst);
void	ft_sp_perc(void);

#endif
