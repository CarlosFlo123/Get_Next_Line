/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:09:59 by cflores-          #+#    #+#             */
/*   Updated: 2018/07/23 02:00:02 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	if ((ptr = (char *)malloc(sizeof(const char) * ft_strlen(s1) + 1)))
	{
		ptr[ft_strlen(s1)] = '\0';
	}
	else
	{
		return (NULL);
	}
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}
