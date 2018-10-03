/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 23:24:11 by cflores-          #+#    #+#             */
/*   Updated: 2018/10/03 03:08:29 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	if ((list = (t_list *)malloc(sizeof(*list))))
	{
		list->content_size = content ? content_size : 0;
		if ((list->content = (void *)malloc(sizeof(content))))
			if (content)
				ft_memcpy(list->content, content, content_size);
			else
				list->content = 0;
		else
			free(list);
		list->next = 0;
	}
	return (list);
}
