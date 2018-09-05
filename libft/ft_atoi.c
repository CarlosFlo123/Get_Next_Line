/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:39:46 by cflores-          #+#    #+#             */
/*   Updated: 2018/07/27 01:18:38 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	register int long	res;
	register int		neg;
	register const char	*s;
	register int long	tmp;

	s = str;
	while (*(s) == '\n' || *(s) == '\t' ||
			*(s) == '\r' || *(s) == '\v' ||
			*(s) == '\f' || *(s) == ' ')
		s++;
	neg = 1;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			neg = -1;
	res = 0;
	while (*s >= '0' && *s <= '9')
	{
		tmp = res * 10 + neg * (*s++ - '0');
		if (neg > 0 && tmp < res)
			return (-1);
		if (neg < 0 && tmp > res)
			return (0);
		res = tmp;
	}
	return ((int)res);
}
