/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:57:36 by cflores-          #+#    #+#             */
/*   Updated: 2018/09/26 06:11:01 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;

	j = ft_strlen(s1);
	i = -1;
	while (*(s2 + ++i))
	{
		*(s1 + j++) = *(s2 + i);
	}
	*(s1 + j) = '\0';
	return (s1);
}
