/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 21:29:09 by cflores-          #+#    #+#             */
/*   Updated: 2018/07/26 14:08:48 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_len(char const *ptr, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (ptr[i] == c)
		i++;
	while (ptr[i] != c && ptr[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**ptr;

	if (!s || !(ptr = (char **)malloc(sizeof(*ptr) *
					(ft_countwords(s, c) + 1))))
		return (0);
	i = -1;
	j = 0;
	while (++i < ft_countwords(s, c))
	{
		k = 0;
		if (!(ptr[i] = ft_strnew(get_word_len(&s[j], c) + 1)))
			ptr[i] = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			ptr[i][k++] = s[j++];
		ptr[i][k] = '\0';
	}
	ptr[i] = 0;
	return (ptr);
}
