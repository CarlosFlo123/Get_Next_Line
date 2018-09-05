/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 21:22:10 by cflores-          #+#    #+#             */
/*   Updated: 2018/07/25 21:08:57 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	int		i;

	if (!s)
		return (0);
	ptr = ft_strnew(ft_strlen(s));
	if (!ptr)
		return (0);
	i = -1;
	while (*(s + ++i))
		*(ptr + i) = f(*(s + i));
	return (ptr);
}
