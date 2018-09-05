/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:02:49 by cflores-          #+#    #+#             */
/*   Updated: 2018/07/26 23:59:04 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*a;
	char	*b;
	size_t	i;

	a = (char *)dst;
	b = (char *)src;
	i = len;
	if (b < a)
		while (i--)
			a[i] = b[i];
	else
		while (i--)
			*a++ = *b++;
	return (dst);
}
