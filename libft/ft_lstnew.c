/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:28:08 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/17 23:36:27 by sslift           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*root;

	if (!(root = (t_list*)malloc(sizeof(*root))))
		return (NULL);
	if (content)
	{
		if (!(root->content = (void*)malloc(content_size)))
		{
			free(root);
			return (NULL);
		}
		root->content = ft_memmove(root->content, content, content_size);
		root->content_size = content_size;
	}
	else
	{
		root->content = NULL;
		root->content_size = 0;
	}
	root->next = NULL;
	return (root);
}
