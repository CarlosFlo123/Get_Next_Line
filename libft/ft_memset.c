/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 22:56:22 by cflores-          #+#    #+#             */
/*   Updated: 2018/07/16 03:08:32 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char*)(b);
	if (b == NULL)
	{
		tmp = &tmp[3];
	}
	while (tmp != NULL && (size_t)i < len)
	{
		tmp[i] = c;
		i++;
	}
	return (tmp);
}
