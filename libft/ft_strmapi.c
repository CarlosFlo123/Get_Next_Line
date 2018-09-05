/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 21:23:01 by cflores-          #+#    #+#             */
/*   Updated: 2018/07/25 22:56:08 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		i;

	i = -1;
	if (!s || !f)
		return (0);
	ptr = ft_strnew(ft_strlen(s));
	if (!ptr)
		return (0);
	while (*(s + ++i))
		*(ptr + i) = f(i, *(s + i));
	return (ptr);
}
