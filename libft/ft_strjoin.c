/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 21:27:20 by cflores-          #+#    #+#             */
/*   Updated: 2018/07/26 12:12:57 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	s1_s;
	size_t	s2_s;

	if (!s1 || !s2)
		return (0);
	s1_s = ft_strlen(s1);
	s2_s = ft_strlen(s2);
	ptr = ft_strnew(s1_s + s2_s);
	if (!ptr)
		return (0);
	i = -1;
	j = -1;
	while (++i < s1_s)
		*(ptr + i) = *(s1 + i);
	while (++j < s2_s)
		*(ptr + i++) = *(s2 + j);
	return (ptr);
}
