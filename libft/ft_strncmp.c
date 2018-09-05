/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:45:41 by cflores-          #+#    #+#             */
/*   Updated: 2018/07/27 19:56:12 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	register unsigned char	*ps1;
	register unsigned char	*ps2;
	register size_t			i;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = n;
	while (i-- && *ps1++ == *ps2++ && *(ps1 - 1))
		;
	return (*--ps1 - *--ps2);
}
