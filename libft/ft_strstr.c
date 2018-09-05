/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:31:30 by cflores-          #+#    #+#             */
/*   Updated: 2018/07/27 02:22:33 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*a;
	char	*b;
	int		i;
	int		n;

	a = (char *)s1;
	b = (char *)s2;
	if (!(*b))
		return (a);
	n = ft_strlen(a) - ft_strlen(b) + 1;
	while (n-- > 0)
	{
		if (*a == *b)
		{
			i = -1;
			while (b[++i])
				if (a[i] != b[i])
					break ;
			if (b[i] == '\0')
				return (a);
		}
		a++;
	}
	return (0);
}
