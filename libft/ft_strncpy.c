/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:13:35 by cflores-          #+#    #+#             */
/*   Updated: 2018/07/19 17:48:06 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;

	i = -1;
	while (++i < len)
	{
		if (*(src + i))
		{
			*(dst + i) = *(src + i);
		}
		else
		{
			while (i < len)
			{
				*(dst + i++) = '\0';
			}
		}
	}
	return (dst);
}
