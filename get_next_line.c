/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:19:53 by cflores-          #+#    #+#             */
/*   Updated: 2018/09/16 15:46:56 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	char	*buffer = 0;
	int		i = 0;
	int		flag = 0;
	char	*tmp = 0;

	line = 0;
	buffer = malloc(sizeof (char *) * BUFF_SIZE + 1);
	//printf("LA PURA FRUTA");
	tmp = malloc(sizeof (char *) * 80);
	line = malloc(sizeof (char **) * 3);
	*line = malloc(sizeof(char *) * 80);
	while (1)
	{
		//fflush( stdin );
		if (fd < 0 || read(fd, buffer, 0) <= 0)
			return (-1);
		read(fd, buffer, BUFF_SIZE);
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				tmp = ft_strncpy(tmp, buffer, i);
				flag = 1;
			}
			if (flag == 0)
				*line = ft_strcat(*line, buffer);
			else
			{
				*line = ft_strcat(*line, tmp);
				break ;
			}
			i++;
		}
		printf("%s | %lu", *line, ft_strlen(*line));
		if (flag == 1)
			break ;
	}
	return (1);
}
