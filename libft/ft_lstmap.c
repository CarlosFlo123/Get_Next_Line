/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 23:29:14 by cflores-          #+#    #+#             */
/*   Updated: 2018/07/27 02:46:41 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*lst_p;

	ret = (lst && f) ? f(lst) : NULL;
	lst_p = ret;
	while (lst_p && lst->next)
	{
		lst_p->next = f(lst->next);
		lst = lst->next;
		lst_p = lst_p->next;
	}
	return (ret);
}
