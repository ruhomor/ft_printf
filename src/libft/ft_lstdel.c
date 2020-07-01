/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:51:16 by kachiote          #+#    #+#             */
/*   Updated: 2019/09/24 18:14:24 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*cur;
	t_list	*next;

	cur = *alst;
	while (cur)
	{
		next = cur->next;
		del(cur->content, cur->content_size);
		free(cur);
		cur = next;
	}
	*alst = NULL;
}
