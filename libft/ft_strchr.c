/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:28:54 by cflores-          #+#    #+#             */
/*   Updated: 2018/07/20 19:14:01 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	tmp;
	int		i;

	ptr = (char *)s;
	tmp = (char)c;
	i = -1;
	while (*ptr != tmp)
	{
		if (*ptr == '\0')
		{
			return (NULL);
		}
		ptr++;
	}
	return (ptr);
}
