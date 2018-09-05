/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 21:29:53 by cflores-          #+#    #+#             */
/*   Updated: 2018/07/26 18:42:54 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		get_len(int n)
{
	size_t			i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char				*ft_itoa(int n)
{
	char			*ptr;
	size_t			len;
	unsigned int	tmp;

	len = get_len(n);
	tmp = n;
	if (n < 0)
	{
		tmp = -n;
		len++;
	}
	if (!(ptr = ft_strnew(len)))
		return (0);
	ptr[--len] = tmp % 10 + '0';
	while (tmp /= 10)
		ptr[--len] = tmp % 10 + '0';
	if (n < 0)
		*(ptr + 0) = '-';
	return (ptr);
}
