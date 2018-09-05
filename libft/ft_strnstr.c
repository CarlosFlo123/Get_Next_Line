/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:33:19 by cflores-          #+#    #+#             */
/*   Updated: 2018/07/28 18:05:13 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	register int	i;
	register char	*hptr;
	register char	*nptr;
	register size_t	n;

	hptr = (char *)haystack;
	nptr = (char *)needle;
	if (!(*nptr))
		return (hptr);
	n = ft_strlen(nptr) - 1;
	len = len < ft_strlen(hptr) ? len : ft_strlen(hptr);
	while (len > n++)
	{
		if (*hptr == *nptr)
		{
			i = -1;
			while (nptr[++i])
				if (hptr[i] != nptr[i])
					break ;
			if (nptr[i] == '\0')
				return (hptr);
		}
		hptr++;
	}
	return (NULL);
}
