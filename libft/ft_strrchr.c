/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:30:00 by cflores-          #+#    #+#             */
/*   Updated: 2018/07/21 00:15:46 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	tmp;

	ptr = (char *)s + ft_strlen(s);
	tmp = (char)c;
	while (*ptr != tmp)
	{
		if (ptr == s)
		{
			return (NULL);
		}
		ptr--;
	}
	return (ptr);
}
