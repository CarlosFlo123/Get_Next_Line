/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:04:27 by cflores-          #+#    #+#             */
/*   Updated: 2018/07/18 02:38:15 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ptr;
	int			i;

	i = -1;
	ptr = (const char *)s;
	while (++i < (int)n)
	{
		if (*(ptr + i) == (char)c)
		{
			return ((void *)ptr + i);
		}
	}
	return (NULL);
}
