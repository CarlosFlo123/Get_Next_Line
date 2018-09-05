/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:20:32 by cflores-          #+#    #+#             */
/*   Updated: 2018/07/20 14:44:56 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_size;
	size_t	src_size;
	int		j;

	i = ft_strlen(dst);
	j = -1;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dstsize < dst_size + 1)
	{
		return (src_size + dstsize);
	}
	else
	{
		while (i < dstsize - 1)
		{
			*(dst + i++) = *(src + ++j);
		}
		*(dst + i) = '\0';
	}
	return (dst_size + src_size);
}
